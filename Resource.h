#ifndef RESOURCE_H
#define RESOURCE_H

#include <list>
#include <tuple>

/**
 * A class representing each resource in the program.
 */
class Resource
{
public:
    /**
     * Create an instance of the Resource object.
     * @param parent the process that create the process in the "this" pointer
     * @param priority the importance of the process, ranging from 0 to 2
     */
    explicit Resource(int id);
    
    /**
     * Return the number of units does the resource in the "this" pointer has
     * @return the number of units does the resource in the "this" pointer has
     */
    int getState();
    
    /**
     * Return the total amount of the resource in the "this" pointer
     * @return the total amount of the resource in the "this" pointer
     */
    int getInventory() const;
    
    /**
     * Return a linked list containing each process in the waitlist.
     * @return a linked list containing each process in the waitlist
     */
    std::list<std::tuple<int, int>> getWaitlist();
    
    /**
     * Set the number of units of the resource in the "this" pointer has
     * @param state the number of units does the resource in the "this" pointer has
     */
    void setState(int state);
    
    /**
     * Append a process to the waitlist.
     * @param id the index of the process in the PCB
     * @param amount the number of units the process wants to get
     */
    void addProcess(int id, int amount);
    
    /**
     * Check if the process owns a resource.
     * @param id the index of a resource
     * @param amount the number of units the process wants to get
     * @return true if the process ID is in the waitlist, false otherwise
     */
    bool findProcess(int id, int amount);
    
    /**
     * Remove a process from the waitlist.
     * @param id the index of the process in the PCB
     */
    void removeProcess(int id);

private:
    // The number of units does the resource in the "this" pointer has
    int state;
    
    // The total amount of the resource in the "this" pointer
    const int INVENTORY;
    
    // A linked list containing a list of processes waiting to get the resource. Each tuple has the process ID and the amount it wants to get
    std::list<std::tuple<int, int>> waitlist;
};

#endif