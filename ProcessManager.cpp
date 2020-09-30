#include "ProcessManager.h"

ProcessManager::ProcessManager()
    : currentProcess{0}
{
    init();
}

void ProcessManager::init()
{
    pcb.fill(nullptr);
    std::shared_ptr<Process> process{new Process(-1, 0)};
    pcb[0] = process;
    rl[0].push_front(0);

    rcb.fill(nullptr);
    for (size_t counter = 0; counter < rcb.size(); ++counter)
    {
        std::shared_ptr<Resource> resource{new Resource(counter)};
        rcb[counter] = resource;
    }
}

void ProcessManager::create(int priority)
{

}

void ProcessManager::destroy(int id)
{

}

void ProcessManager::request(int id, int amount)
{

}

void ProcessManager::release(int id, int amount)
{

}

void ProcessManager::scheduler()
{
    for (size_t counter = 2; counter >= 0; --counter)
    {
        if (rl[counter].size() != 0 && pcb[rl[counter].front()]->getState() == READY)
        {
            currentProcess = rl[counter].front();
            break;
        }
    }
}

void ProcessManager::timeout()
{
    int priority = pcb[currentProcess]->getPriority(); 
    rl[priority].pop_front();
    rl[priority].push_back(currentProcess);
    scheduler();
}