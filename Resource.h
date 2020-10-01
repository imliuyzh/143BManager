#ifndef RESOURCE_H
#define RESOURCE_H

#include <list>
#include <tuple>

/**
 * A class for representing each resource in this program.
 */ 
class Resource
{
public:
    /**
     * Create a Resource object
     * @param id an int for the index of the resource in the RCB
     */ 
    explicit Resource(int id);

    /**
     * See how many units of the resource are utilized by other processes
     * @return an int showing how much of the resource is being used
     */ 
    int getState();

    /**
     * Set the number of resource units that are being used
     * @param state an int for the number of resource units that are being used
     */ 
    void setState(int state);

    /**
     * See the total units of the resources
     * @return an int for the total units of the resource
     */
    int getInventory() const;

    /**
     * Retrieve the list where every process in the list is waiting for this resource
     * @return a list of processes waiting for the resource
     */ 
    std::list<std::tuple<int, int>> getProcessWaitlist();

    /**
     * Add a process in the waitlist
     * @param id an int representing the index of the process in the PCB
     * @param amount an int for how many units does the process needs
     */
    void addProcess(int id, int amount);

    /**
     * Find if a process is in the waitlist
     * @param id an int representing the index of the process in the PCB
     * @return true if the process is in the waitlist, false otherwise
     */ 
    bool findProcess(int id);
    
    /**
     * Remove a process in the waitlist
     * @param id an int representing the index of the process in the PCB
     */
    void removeProcess(int id);

private:
    // How many units of resource are being used
    int state;

    // Total units of the resource
    const int INVENTORY;

    // A linked list storing the ID of processes waiting to get the resource and how many units do they want
    std::list<std::tuple<int, int>> waitlist;
};

#endif