#ifndef PROCESS_MANAGER_UI_H
#define PROCESS_MANAGER_UI_H

#include <iostream>
#include <regex>
#include <string>
#include "ProcessManager.h"

class ProcessManagerUI
{
public:
    ProcessManagerUI();
    void getInput();

private:
    void performAction(std::cmatch& matches);

private:
    ProcessManager manager;
};

#endif