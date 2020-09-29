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

void Resource::addProcess(int id, int amount)
{
    waitlist.push_back(std::make_tuple(id, amount));
}

void Resource::removeProcess(int id, int amount)
{
    waitlist.remove(std::make_tuple(id, amount));
}