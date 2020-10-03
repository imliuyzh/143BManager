#include "Process.h"

// Please read the comments in the header file to understand the functionalities of each method.
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

std::list<int> Process::getChildren()
{
    return children;
}

void Process::addChild(int id)
{
    children.push_back(id);
}

bool Process::findChild(int id)
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

void Process::removeChild(int id)
{
    children.remove(id);
}

void Process::addResource(int id, int amount)
{
    int newAmount = findResource(id) + amount;
    resources.remove_if([&](std::tuple<int, int> record) { return std::get<0>(record) == id; });
    resources.push_back(std::make_tuple(id, newAmount));
}

int Process::findResource(int id)
{
    for (std::tuple<int, int>& resource : resources)
    {
        if (std::get<0>(resource) == id)
        {
            return std::get<1>(resource);
        }
    }
    return 0;
}
 
std::list<std::tuple<int, int>> Process::getResources()
{
    return resources;
}

void Process::removeResource(int id, int amount)
{
    for (std::tuple<int, int>& resource : resources)
    {
        if (std::get<0>(resource) == id)
        {
            std::get<1>(resource) -= amount;
            break;
        }
    }

    resources.remove_if(
        [&](std::tuple<int, int> record) { return std::get<0>(record) == id && std::get<1>(record) - amount == 0; }
    );
}