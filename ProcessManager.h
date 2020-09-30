#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

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
    void timeout();

private:
};

#endif