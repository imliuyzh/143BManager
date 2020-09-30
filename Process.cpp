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
 * Give the index of the parent process in the PCB
 * @return the index of the parent process in the PCB
 */ 
int Process::getParent() const
{
    return PARENT;
}

/**
 * Give the importance of the process
 * @return an int from 0-2
 */
int Process::getPriority() const
{
    return PRIORITY;
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
 * Remove the ID of a resource in the list of resources
 * @param id the index of the child process in RCB
 */ 
void Process::removeResource(int id, int amount)
{
    resources.remove(std::make_tuple(id, amount));
}