#include "ProcessManager.h"

ProcessManager::ProcessManager()
    : currentProcess{0}
{
    init();
}

int ProcessManager::init()
{
    pcb.fill(nullptr);
    std::shared_ptr<Process> process{new Process(-1, 0)};
    pcb[0] = process;

    rcb.fill(nullptr);
    for (size_t counter = 0; counter < rcb.size(); ++counter)
    {
        std::shared_ptr<Resource> resource{new Resource(counter)};
        rcb[counter] = resource;
    }

    for (std::list<int> rl : rls)
    {
        rl.clear();
    }
    rls[0].push_front(0);

    currentProcess = 0;
    return currentProcess;
}

int ProcessManager::findFreeSpace()
{
    for (size_t counter = 1; counter < pcb.max_size(); ++counter)
    {
        if (pcb[counter] == nullptr)
        {
            return counter;
        }
    }
    return -1;
}

bool ProcessManager::createCheck(int freeSpace, int priority)
{
    return freeSpace > 0 && priority > 0 && priority <= 2;
}

int ProcessManager::create(int priority)
{
    int freeSpace = findFreeSpace();   
    if (createCheck(freeSpace, priority) == true)
    {
        std::shared_ptr<Process> process{new Process(currentProcess, priority)};
        pcb[freeSpace] = process;
        pcb[currentProcess]->addChild(freeSpace);
        rls[priority].push_back(freeSpace);
        return scheduler();
    }
    return -1;
}

bool ProcessManager::destroyCheck(int id, int parent)
{
    return id >= 0 && id < static_cast<int>(pcb.max_size()) && pcb[id] != nullptr && pcb[parent]->findChild(id) == true;
}

// destroy(0)?
int ProcessManager::destroy(int id)
{
    int parent = pcb[id]->getParent();
    if (destroyCheck(id, parent) == true)
    {
        std::list<int> childProcesses = pcb[id]->getChildren();
        for (int childProcess : childProcesses)
        {
            destroy(childProcess);
        }

        pcb[parent]->removeChild(id);

        rls[pcb[id]->getPriority()].remove(id);
        for (std::shared_ptr<Resource> resourceBlock : rcb)
        {
            resourceBlock->removeProcess(id);
        }

        std::list<std::tuple<int, int>> resources = pcb[id]->getResources();
        for (std::tuple<int, int> resource : resources)
        {
            release(std::get<0>(resource), std::get<1>(resource));
        }

        pcb[id] = nullptr;
        return scheduler();
    }
    return -1;
}

bool ProcessManager::requestCheck(int id, int amount)
{
    return currentProcess != 0 && id > 0 && id <= 3 && pcb[id]->findResource(id) == false && amount > 0 && amount <= rcb[id]->getInventory();
}

// Request more even if it got some?
int ProcessManager::request(int id, int amount)
{
    if (requestCheck(id, amount) == true)
    {
        int currentAmount = rcb[id]->getState();
        if (currentAmount >= amount)
        {
            rcb[id]->setState(currentAmount - amount);
            pcb[currentProcess]->addResource(id, amount);
            return currentProcess;
        }
        else
        {
            pcb[currentProcess]->setState(BLOCKED);
            rls[pcb[currentProcess]->getPriority()].remove(currentProcess);
            rcb[id]->addProcess(currentProcess, amount);
            return scheduler();
        }
    }
    return -1;
}

bool ProcessManager::releaseCheck(int id, int amount)
{
    return currentProcess != 0 && id >= 0 && id <= 3 && pcb[currentProcess]->findResource(id) == true && amount > 0 && amount <= rcb[id]->getInventory();
}

int ProcessManager::release(int id, int amount)
{
    if (releaseCheck(id, amount) == true)
    {
        pcb[currentProcess]->removeResource(id, amount);
        rcb[id]->setState(rcb[id]->getState() + amount);

        std::list<std::tuple<int, int>> waitlist = rcb[id]->getWaitlist();
        while (waitlist.empty() == false && rcb[id]->getState() > 0)
        {
            std::tuple<int, int> record = waitlist.front();
            waitlist.pop_front();

            if (rcb[id]->getState() >= std::get<1>(record))
            {
                rcb[id]->setState(rcb[id]->getState() - std::get<1>(record));
                pcb[std::get<0>(record)]->addResource(id, std::get<1>(record));
                pcb[std::get<0>(record)]->setState(READY);
                rcb[id]->removeProcess(std::get<0>(record));
                rls[pcb[std::get<0>(record)]->getPriority()].push_back(std::get<0>(record));
            }
        }
        return scheduler();
    }
    return -1;
}

int ProcessManager::scheduler()
{
    for (int counter = 2; counter >= 0; --counter)
    {
        if (rls[counter].size() != 0 && pcb[rls[counter].front()]->getState() == READY)
        {
            currentProcess = rls[counter].front();
            break;
        }
    }
    return currentProcess;
}

int ProcessManager::timeout()
{
    int priority = pcb[currentProcess]->getPriority(); 
    rls[priority].pop_front();
    rls[priority].push_back(currentProcess);
    return scheduler();
}