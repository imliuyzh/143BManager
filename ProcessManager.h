#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

#include <array>
#include <memory>
#include "Process.h"
#include "Resource.h"

class ProcessManager
{
public:
    ProcessManager();
    int init();
    int create(int priority);
    int destroy(int id);
    int request(int id, int amount);
    int release(int id, int amount);
    int scheduler();
    int timeout();

private:
    int findFreeSpace();
    bool createCheck(int freeSpace, int priority);
    bool destroyCheck(int id, int parent);
    bool requestCheck(int currentAmount, int id, int amount);
    bool releaseCheck(int id);

private:
    std::array<std::shared_ptr<Process>, 16> pcb;
    std::array<std::shared_ptr<Resource>, 4> rcb;
    std::array<std::list<int>, 3> rl;
    int currentProcess;
};

#endif