#ifndef PROCESS_MANAGER_UI_H
#define PROCESS_MANAGER_UI_H

#include <iostream>
#include <regex>
#include <string>
#include "ProcessManager.h"
#include "Utilities.h"

class ProcessManagerUI
{
public:
    ProcessManagerUI();
    void getInput();

private:
    void performAction(std::smatch& matches);

private:
    ProcessManager manager;
};

#endif