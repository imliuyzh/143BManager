#include "Process.h"

Process::Process(int parent, int priority)
    : state{READY}, PARENT{parent}, PRIORITY{priority}
{
}

ProcessState Process::getState()
{
    return state;
}

void Process::setState(ProcessState state)
{
    this->state = state;
}

int Process::getParent()
{
    return PARENT;
}

int Process::getPriority()
{
    return PRIORITY;
}

std::list<int> Process::getChildProcesses()
{
    return children;
}

void Process::addChildProcess(int id)
{
    children.push_back(id);
}

bool Process::findChildProcess(int id)
{
    for (int child : children)
    {
        if (child == id)
        {
            return true;
        }
    }
    return false;
}

void Process::removeChildProcess(int id)
{
    children.remove(id);
}

void Process::addResource(int id, int amount)
{
    resources.push_back(std::make_tuple(id, amount));
}

bool Process::findResource(int id)
{
    for (std::tuple<int, int>& resource : resources)
    {
        if (std::get<0>(resource) == id)
        {
            return true;
        }
    }
    return false;
}
 
std::list<std::tuple<int, int>> Process::getResources()
{
    return resources;
}

void Process::removeResource(int id)
{
    resources.remove_if([&](std::tuple<int, int> record) { return std::get<0>(record) == id; });
}