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
     * Changed the state of process to READY/BLOCKED
     * @param state READY or BLOCKED
     */ 
    void setState(ProcessState state);

    /**
     * Give the index of the parent process in the PCB
     * @return the index of the parent process in the PCB
     */ 
    int getParent();

    /**
     * Give the importance of the process
     * @return an int from 0-2
     */
    int getPriority();

    /**
     * Get a list of child processes
     * @return a linked list of the child processes in the process
     */ 
    std::list<int> getChildProcesses();

    /**
     * Add the ID of a process to the list of child process
     * @param id the index of the child process in PCB
     */ 
    void addChildProcess(int id);

    /**
     * See if the specified process is one of the child processes
     * @param id the index of the child process in PCB
     * @return true if the child process exists, false otherwise
     */
    bool findChildProcess(int id); 

    /**
     * Remove the ID of a process in the list of child process
     * @param id the index of the child process in PCB
     */ 
    void removeChildProcess(int id);

    /**
     * Add the ID of a resource to the list of resources
     * @param id the index of the resource in RCB
     * @param amount how many units of the resource does the process need
     */ 
    void addResource(int id, int amount);

    /**
     * Remove the ID of a resource in the list of resources
     * @param id the index of the child process in RCB
     */ 
    void removeResource(int id);

    /**
     * Retrieve a list of resources gathered by the process
     * @return a linked list of the resources of the process
     */ 
    std::list<std::tuple<int, int>> Process::getResources();

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