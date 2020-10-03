#ifndef PROCESS_H
#define PROCESS_H

#include <list>
#include <tuple>

// An enum representing the state of the process. Note that it does not have running since it can implicitly implemented by finding the first process in the running list.
enum ProcessState { READY, BLOCKED };

/**
 * A class representing each process in the program.
 */
class Process
{
public:
    /**
     * Create an instance of the Process object.
     * @param parent the process that create the process in the "this" pointer
     * @param priority the importance of the process, ranging from 0 to 2
     */
    Process(int parent, int priority);
    
    /**
     * Return the state of the process.
     * @return READY or BLOCKED
     */
    ProcessState getState();
    
    /**
     * Return the parent of the process.
     * @return the process that create the process in the "this" pointer
     */
    int getParent();
    
    /**
     * Return the importance of the process.
     * @return an int from 0 to 2
     */
    int getPriority();
    
    /**
     * Return a linked list containing each process' child processes.
     * @return a linked list containing each process' child processes
     */
    std::list<int> getChildren();
    
    /**
     * Return a linked list representing each resource in the program.
     * @return a linked list representing each resource in the program
     */
    std::list<std::tuple<int, int>> getResources();
    
    /**
     * Return the state of the process.
     * @return READY or BLOCKED
     */
    void setState(ProcessState state);
    
    /**
     * Append the ID of a child process.
     * @param id the index of the child process in the PCB
     */
    void addChild(int id);
    
    /**
     * Check if the ID is a child process.
     * @param id the index of a process
     * @return true if the ID is one of the child processes, false otherwise
     */
    bool findChild(int id);
    
    /**
     * Remove a child process.
     * @param id the index of the child process in the PCB
     */
    void removeChild(int id);
    
    /**
     * Append the ID of a resource.
     * @param id the index of the resource in the RCB
     * @param amount the amount that the process want to get
     */
    void addResource(int id, int amount);
    
    /**
     * Check if the process owns a resource.
     * @param id the index of a resource
     * @return a number greater than 0 if the ID is one of the resources, 0 otherwise
     */
    int findResource(int id);
    
    /**
     * Remove a resource.
     * @param id the index of the resource in the RCB
     * @param amount the amount that the process want to remove
     */
    void removeResource(int id, int amount);

private:
    // The state of the process, can be READY or BLOCKED (RUNNING is implicitly represented by the first process in the highest level of the running list)
    ProcessState state;
    
    // PARENT - The process that create the process in the "this" pointer
    // PRIORITY - The importance of the process, ranging from 0 to 2
    const int PARENT, PRIORITY;
    
    // A linked list containing each process' child processes
    std::list<int> children;
    
    // A linked list representing each resource in the program. Each entry has a tuple containing a resource ID and the amount that the process has
    std::list<std::tuple<int, int>> resources;
};

#endif