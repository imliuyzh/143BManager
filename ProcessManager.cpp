#include "ProcessManager.h"

ProcessManager::ProcessManager()
    : pcb{new Process*[16]}, rcb{new Resource*[4]}
{
    init();
}

void ProcessManager::create(int priority)
{

}

void ProcessManager::destroy(int id)
{

}

void ProcessManager::request(int id, int amount)
{

}

void ProcessManager::release(int id, int amount)
{

}
    
void ProcessManager::timeout()
{

}
    
void ProcessManager::init()
{

}