#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

#include <array>
#include <memory>
#include "Process.h"
#include "Resource.h"

/**
 * A class for the core functionalities and data in this program.
 */
class ProcessManager
{
public:
    /**
     * Create an instance of the ProcessManager object.
     */
    ProcessManager();
    
    /**
     * Initialize all the critical data that the program needs.
     * @return the ID of the next process that will run, which is 0
     */
    int init();
    
    /**
     * Create a process. The new process will be a child process of the current process.
     * @param priority the importance of the process, ranging from 0 to 2
     * @return the ID of the next process that will run
     */
    int create(int priority);
    
    /**
     * Destroy a process and all its child processes.
     * @param id the index of the process in the PCB
     * @param parent the index of the parent process for the one in the parameter id (-1 is for the current process)
     * 
     * @return the ID of the next process that will run
     */
    int destroy(int id, int parent = -1);
    
    /**
     * Request a resource for the current process.
     * @param id the index of the resource in the RCB
     * @param amount the amount that the process want to get
     * @return the ID of the next process that will run
     */
    int request(int id, int amount);
    
    /**
     * Release a resource for a process.
     * @param id the index of the resource in the RCB
     * @param amount the amount that the process want to release
     * @param process -1 for current process, a number greater than 0 for others
     * @return the ID of the next process that will run
     */
    int release(int id, int amount, int process);
    
    /**
     * Pick a new process to run. The one with a higher priority will run first.
     * @return the ID of the next process that will run
     */
    int scheduler();
    
    /**
     * Pause the current process and pick a new process to run.
     * @return the ID of the next process that will run
     */
    int timeout();

private:
    /**
     * Get the first index in the pcb array that is empty.
     * @return the first index in the pcb array that has a nullptr
     */
    int findFreeSpace();
    
    /**
     * Check if the parameters for create() are legal.
     * @param freeSpace the first index in the pcb array that is empty
     * @param priority the importance of the process, ranging from 0 to 2
     * @return true if all the parameters are correct, false otherwise
     */
    bool createCheck(int freeSpace, int priority);
    
    /**
     * Check if the parameters for destroy() are legal.
     * @param id the index of the process in the PCB
     * @param parent the index of the parent process for the one in the parameter id
     * @return true if all the parameters are correct, false otherwise
     */
    bool destroyCheck(int id, int parent);
    
    /**
     * Check if the parameters for request() are legal.
     * @param id the index of the resource in the RCB
     * @param amount the amount that the process want to get
     * @return true if all the parameters are correct, false otherwise
     */
    bool requestCheck(int id, int amount);
    
    /**
     * Check if the parameters for release() are legal.
     * @param id the index of the resource in the RCB
     * @param amount the amount that the process want to release
     * @param process -1 for current process, a number greater than 0 for others
     * @return true if all the parameters are correct, false otherwise
     */
    bool releaseCheck(int id, int amount, int process);

private:
    // An array for storing 16 processes
    std::array<std::shared_ptr<Process>, 16> pcb;
    
    // An array for storing 4 resources
    std::array<std::shared_ptr<Resource>, 4> rcb;
    
    // An array for storing 3 levels of ready lists
    std::array<std::list<int>, 3> rls;
    
    // The ID of the process that is currently running
    int currentProcess;
};

#endif
