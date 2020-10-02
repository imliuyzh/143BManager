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

    for (size_t counter = 0; counter < rls.size(); ++counter)
    {
        rls[counter].clear();
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

bool ProcessManager::destroyCheck(int id)
{
    return id > 0 && id < static_cast<int>(pcb.max_size())
        && pcb[id] != nullptr && pcb[pcb[id]->getParent()]->findChild(id) == true;
}

int ProcessManager::destroy(int id)
{
    if (destroyCheck(id) == true)
    {
        int parent = pcb[id]->getParent();
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
            release(std::get<0>(resource), std::get<1>(resource), id);
        }

        pcb[id] = nullptr;
        return scheduler();
    }
    return -1;
}

bool ProcessManager::requestCheck(int id, int amount)
{
    return currentProcess > 0 && id >= 0 && id <= 3
        && amount > 0 && (pcb[currentProcess]->findResource(id) + amount) <= rcb[id]->getInventory();
}

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

// Can a process' state set to BLOCKED if its need cannot be met after requesting the resource for the second time?
bool ProcessManager::releaseCheck(int id, int amount, int process)
{
    int currentAmount = pcb[process]->findResource(id);
    return process > 0 && id >= 0 && id <= 3
        && amount > 0 && amount <= currentAmount && amount <= rcb[id]->getInventory();
}

int ProcessManager::release(int id, int amount, int process=-1)
{
    int targetProcess = (process == -1) ? currentProcess : process;
    if (releaseCheck(id, amount, targetProcess) == true)
    {
        pcb[targetProcess]->removeResource(id, amount);
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
            else
            {
                break;
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