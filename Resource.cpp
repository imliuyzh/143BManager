#include "Resource.h"

Resource::Resource(int id)
    : state{0}, INVENTORY{(id <= 1) ? 1 : id}
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

std::list<std::tuple<int, int>> Resource::getProcessWaitlist()
{
    return waitlist;
}

void Resource::addProcess(int id, int amount)
{
    waitlist.push_back(std::make_tuple(id, amount));
}

bool Resource::findProcess(int id)
{
    for (std::tuple<int, int>& record : waitlist)
    {
        if (std::get<0>(record) == id)
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