#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

#include <memory>
#include "Process.h"
#include "Resource.h"

class ProcessManager
{
public:
    ProcessManager();
    void create(int priority);
    void destroy(int id);
    void request(int id, int amount);
    void release(int id, int amount);
    void timeout();
    void init();

private:
    std::shared_ptr<std::shared_ptr<Process>> pcb;
    std::shared_ptr<std::shared_ptr<Resource>> rcb;
};

#endif