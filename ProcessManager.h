#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

#include <array>
#include <memory>
#include "Process.h"
#include "Resource.h"
#include "Utilities.h"

class ProcessManager
{
public:
    ProcessManager();
    void init();
    void create(int priority);
    void destroy(int id);
    void request(int id, int amount);
    void release(int id, int amount);
    void scheduler();
    void timeout();

private:
    std::array<std::shared_ptr<Process>, 16> pcb;
    std::array<std::shared_ptr<Resource>, 4> rcb;
    std::array<std::list<int>, 3> rl;
    int currentProcess;
};

#endif