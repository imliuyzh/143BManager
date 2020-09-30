#ifndef PROCESS_H
#define PROCESS_H

#include <list>
#include <tuple>

// An enum representing the state of the process. Note that it does not have running since it can implicitly implemented by finding the first process in the running list.
enum ProcessState { READY, BLOCKED };

/**
 * A class represents each process in this program.
 */
class Process
{
public:
    /**
     * Create a Process object
     * @param parent an int representing the index of parent process in the PCB
     * @param priority an int representing the importance of the process
     */ 
    Process(int parent, int priority);

    /**
     * Show if the process is in the ready state or blocked state
     * @return READY or BLOCKED
     */ 
    ProcessState getState();

    /**
     * Give the index of the parent process in the PCB
     * @return the index of the parent process in the PCB
     */ 
    int getParent() const;

    /**
     * Give the importance of the process
     * @return an int from 0-2
     */
    int getPriority() const;

    /**
     * Add the ID of a process to the list of child process
     * @param id the index of the child process in PCB
     */ 
    void addChildProcess(int id);

    /**
     * Remove the ID of a process in the list of child process
     * @param id the index of the child process in PCB
     */ 
    void removeChildProcess(int id);

    /**
     * Add the ID of a resource to the list of resources
     * @param id the index of the resource in RCB
     */ 
    void addResource(int id, int amount);

    /**
     * Remove the ID of a resource in the list of resources
     * @param id the index of the child process in RCB
     */ 
    void removeResource(int id, int amount);

private:
    // Can be READY or BLOCKED
    ProcessState state;

    // PARENT - ID of the process that creates the process in the "this" pointer
    // PRIORITY - A number from 0-2 indicating the importance of the process (0 is lowest, 2 is highest)
    const int PARENT, PRIORITY;

    // A linked list of child process IDs
    std::list<int> children;

    // A linked list of system resources and their amount that the process gathers
    std::list<std::tuple<int, int>> resources;
};

#endif