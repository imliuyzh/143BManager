#ifndef RESOURCE_H
#define RESOURCE_H

#include <list>
#include <tuple>

class Resource
{
public:
    explicit Resource(int id);
    int getState();
    int getInventory() const;
    std::list<std::tuple<int, int>> getWaitlist();
    void setState(int state);
    void addProcess(int id, int amount);
    bool findProcess(int id, int amount);
    void removeProcess(int id);

private:
    int state;
    const int INVENTORY;
    std::list<std::tuple<int, int>> waitlist;
};

#endif