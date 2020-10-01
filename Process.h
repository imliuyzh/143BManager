#ifndef PROCESS_H
#define PROCESS_H

#include <list>
#include <tuple>

// An enum representing the state of the process. Note that it does not have running since it can implicitly implemented by finding the first process in the running list.
enum ProcessState { READY, BLOCKED };

class Process
{
public:
    Process(int parent, int priority);
    ProcessState getState();
    void setState(ProcessState state);
    int getParent();
    int getPriority();
    std::list<int> getChildProcesses();
    void addChildProcess(int id);
    bool findChildProcess(int id);
    void removeChildProcess(int id);
    void addResource(int id, int amount);
    bool findResource(int id);
    void removeResource(int id);
    std::list<std::tuple<int, int>> getResources();

private:
    ProcessState state;
    const int PARENT, PRIORITY;
    std::list<int> children;
    std::list<std::tuple<int, int>> resources;
};

#endif