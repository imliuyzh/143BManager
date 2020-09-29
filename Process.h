#ifndef PROCESS_H
#define PROCESS_H

#include <list>

enum ProcessState { READY, BLOCKED };
class Process
{
public:
    Process(int parent, int priority);
    ProcessState getState();
    int getParent() const;
    int getPriority() const;
    void addChildProcess(int id);
    void removeChildProcess(int id);
    void addResource(int id);
    void removeResource(int id);

private:
    ProcessState state;
    const int PARENT, PRIORITY;
    std::list<int> children, resources;
};

#endif