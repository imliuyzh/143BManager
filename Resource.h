#ifndef RESOURCE_H
#define RESOURCE_H

#include <list>
#include <tuple>

class Resource
{
public:
    explicit Resource(int id);
    int getState();
    void setState(int state);
    int getInventory() const;
    std::list<std::tuple<int, int>> getProcessWaitlist();
    void addProcess(int id, int amount);
    bool findProcess(int id);
    void removeProcess(int id);

private:
    int state;
    const int INVENTORY;
    std::list<std::tuple<int, int>> waitlist;
};

#endif