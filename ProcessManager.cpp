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
    rl[0].push_front(0);
    currentProcess = 0;

    rcb.fill(nullptr);
    for (size_t counter = 0; counter < rcb.size(); ++counter)
    {
        std::shared_ptr<Resource> resource{new Resource(counter)};
        rcb[counter] = resource;
    }

    for (std::list<int> processList : rl)
    {
        processList.clear();
    }

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

int ProcessManager::create(int priority)
{
    int freeSpace = findFreeSpace();
    if (freeSpace > 0 && priority > 0 && priority <= 2)
    {
        std::shared_ptr<Process> process{new Process(currentProcess, priority)};
        pcb[freeSpace] = process;
        pcb[currentProcess]->addChildProcess(freeSpace);
        rl[priority].push_back(freeSpace);
        return scheduler();
    }
    else
    {
        return -1;
    }
}

int ProcessManager::destroy(int id)
{
    int parent = pcb[id]->getParent();
    if (id >= 0 && id < pcb.max_size() && pcb[parent]->findChildProcess(id) == true)
    {
        std::list<int> childProcesses = pcb[id]->getChildProcesses();
        for (int childProcess : childProcesses)
        {
            destroy(childProcess);
        }

        pcb[parent]->removeChildProcess(id);

        rl[pcb[id]->getPriority()].remove(id);
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
    else
    {
        return -1;
    }
}

int ProcessManager::request(int id, int amount)
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
        rl[pcb[currentProcess]->getPriority()].remove(currentProcess);
        rcb[id]->addProcess(currentProcess, amount);
        return scheduler();
    }
}

int ProcessManager::release(int id, int amount)
{
    pcb[currentProcess]->removeResource(id);
    rcb[id]->setState(rcb[id]->getState() + amount);

    std::list<std::tuple<int, int>> waitlist = rcb[id]->getProcessWaitlist();
    while (waitlist.empty() == false && rcb[id]->getState() > 0)
    {
        std::tuple<int, int> record = waitlist.front();
        waitlist.pop_front();

        if (rcb[id]->getState() >= amount)
        {
            rcb[id]->setState(rcb[id]->getState() - amount);
            pcb[std::get<0>(record)]->addResource(id, amount);
            pcb[std::get<0>(record)]->setState(READY);
            rcb[id]->removeProcess(std::get<0>(record));
            rl[pcb[std::get<0>(record)]->getPriority()].push_back(std::get<0>(record));
        }
    }
    return scheduler();
}

int ProcessManager::scheduler()
{
    for (size_t counter = 2; counter >= 0; --counter)
    {
        if (rl[counter].size() != 0 && pcb[rl[counter].front()]->getState() == READY)
        {
            currentProcess = rl[counter].front();
            break;
        }
    }
    return currentProcess;
}

int ProcessManager::timeout()
{
    int priority = pcb[currentProcess]->getPriority(); 
    rl[priority].pop_front();
    rl[priority].push_back(currentProcess);
    return scheduler();
}