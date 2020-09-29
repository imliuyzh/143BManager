#include "Process.h"

Process::Process(int parent, int priority)
    : state{READY}, PARENT{parent}, PRIORITY{priority}
{
}

ProcessState Process::getState()
{
    return state;
}

int Process::getParent() const
{
    return PARENT;
}

int Process::getPriority() const
{
    return PRIORITY;
}

void Process::addChildProcess(int id)
{
    children.push_back(id);
}

void Process::removeChildProcess(int id)
{
    children.remove(id);
}

void Process::addResource(int id)
{
    resources.push_back(id);
}

void Process::removeResource(int id)
{
    resources.remove(id);
}