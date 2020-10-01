#include "ProcessManagerUI.h"

/**
 * Create a ProcessManagerUI object
 */ 
ProcessManagerUI::ProcessManagerUI()
{
    writeOutput(0, true, true);
}

/**
 * Parse the commands from the file
 */ 
void ProcessManagerUI::getInput()
{
    std::string rawInput, temp;
    std::smatch matches;
    const std::regex INPUT_PATTERN("^(cr|de|rq|rl|to|in){1} {0,1}([0-9]*) {0,1}([0-9]*)$");

    while (std::getline(std::cin, rawInput))
    {
        std::cin >> temp;
        bool result = std::regex_match(rawInput, matches, INPUT_PATTERN);
        if (result == true) 
        {
            performAction(matches);
        }
        else if (rawInput != "" && result == false)
        {
            writeOutput(-1);
        }
    }
}

/**
 * Call the methods in the manager variable depending on the commands
 * @param matches an object containing the initial string and matched phrases
 */ 
void ProcessManagerUI::performAction(std::smatch& matches)
{
    try
    {
        std::string original = matches[0].str(), first = matches[1].str(), second = matches[2].str(), third = matches[3].str();
        if (first == "in" && second == "" && third == "")
        {
            int currentProcess = manager.init();
            writeOutput(currentProcess, true, false);
        }
        else if (first == "to" && second == "" && third == "")
        {
            int currentProcess = manager.timeout();
            writeOutput(currentProcess);
        }
        else if (first == "cr" && second != "" && third == "")
        {
            manager.create(std::stoi(second));
        }
        else if (first == "de" && second != "" && third == "")
        {
            manager.destroy(std::stoi(second));
        }
        else if (first == "rq" && second != "" && third != "")
        {
            manager.request(std::stoi(second), std::stoi(third));
        }
        else if (first == "rl" && second != "" && third != "")
        {
            manager.release(std::stoi(second), std::stoi(third));
        }
        else
        {
            writeOutput(-1);
        }
    }
    catch (...)
    {
        writeOutput(-1);
    }
}