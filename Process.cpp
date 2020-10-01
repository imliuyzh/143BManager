#include "Process.h"

/**
 * Create a Process object
 * @param parent an int representing the index of parent process in the PCB
 * @param priority an int representing the importance of the process
 */ 
Process::Process(int parent, int priority)
    : state{READY}, PARENT{parent}, PRIORITY{priority}
{
}

/**
 * Show if the process is in the ready state or blocked state
 * @return READY or BLOCKED
 */ 
ProcessState Process::getState()
{
    return state;
}

/**
 * Changed the state of process to READY/BLOCKED
 * @param state READY or BLOCKED
 */ 
void Process::setState(ProcessState state)
{
    this->state = state;
}

/**
 * Give the index of the parent process in the PCB
 * @return the index of the parent process in the PCB
 */ 
int Process::getParent()
{
    return PARENT;
}

/**
 * Give the importance of the process
 * @return an int from 0-2
 */
int Process::getPriority()
{
    return PRIORITY;
}

/**
 * Retrieve a list of child processes
 * @return a linked list of the child processes in the process
 */ 
std::list<int> Process::getChildProcesses()
{
    return children;
}

/**
 * Add the ID of a process to the list of child process
 * @param id the index of the child process in PCB
 */ 
void Process::addChildProcess(int id)
{
    children.push_back(id);
}

/**
 * See if the specified process is one of the child processes
 * @return true if the child process exists, false otherwise
 */
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

/**
 * Remove the ID of a process in the list of child process
 * @param id the index of the child process in PCB
 */ 
void Process::removeChildProcess(int id)
{
    children.remove(id);
}

/**
 * Add the ID of a resource to the list of resources
 * @param id the index of the resource in RCB
 */ 
void Process::addResource(int id, int amount)
{
    resources.push_back(std::make_tuple(id, amount));
}

/**
 * Retrieve a list of resources gathered by the process
 * @return a linked list of the resources of the process
 */ 
std::list<std::tuple<int, int>> Process::getResources()
{
    return resources;
}

/**
 * Remove the ID of a resource in the list of resources
 * @param id the index of the child process in RCB
 */ 
void Process::removeResource(int id)
{
    resources.remove_if([&](std::tuple<int, int> record) { std::get<0>(record) == id; });
}