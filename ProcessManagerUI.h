#ifndef PROCESS_MANAGER_UI_H
#define PROCESS_MANAGER_UI_H

#include <fstream>
#include <regex>
#include <string>
#include "ProcessManager.h"
#include "Utilities.h"

/**
 * A class for receiving commands from the input file.
 */ 
class ProcessManagerUI
{
public:
    /**
     * Create an instance of the ProcessManagerUI object.
     */ 
    ProcessManagerUI();

    /**
     * Parse the commands from the file.
     * @param filePath a string for the file directory
     */ 
    void getInput(char* filePath);

private:
    /**
     * Call the methods in the manager variable depending on the commands.
     * @param matches an object containing the initial string and matched phrases
     */ 
    void performAction(std::smatch& matches);

private:
    // An instance of ProcessManager for the core mechanism of the program
    ProcessManager manager;
};

#endif