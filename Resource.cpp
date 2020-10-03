#include "Resource.h"

// Please read the comments in the header file to understand the functionalities of each method.
Resource::Resource(int id)
    : state{(id <= 1) ? 1 : id}, INVENTORY{(id <= 1) ? 1 : id}
{
}

int Resource::getState()
{
    return state;
}

void Resource::setState(int state)
{
    this->state = state;
}

int Resource::getInventory() const
{
    return INVENTORY;
}

std::list<std::tuple<int, int>> Resource::getWaitlist()
{
    return waitlist;
}

void Resource::addProcess(int id, int amount)
{
    waitlist.push_back(std::make_tuple(id, amount));
}

bool Resource::findProcess(int id, int amount)
{
    for (std::tuple<int, int>& record : waitlist)
    {
        if (std::get<0>(record) == id && std::get<1>(record) == amount)
        {
            return true;
        }
    }
    return false;
}

void Resource::removeProcess(int id)
{
    waitlist.remove_if([&](std::tuple<int, int> record) { return std::get<0>(record) == id; });
}