#include "ProcessManagerUI.h"

ProcessManagerUI::ProcessManagerUI()
{
    manager.init();
}

void ProcessManagerUI::getInput()
{
    std::string rawInput, temp;
    std::cmatch matches;
    const std::regex INPUT_PATTERN("^(cr|de|rq|rl|to|in){1} {0,1}([0-9]*) {0,1}([0-9]*)$");

    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, rawInput);
        std::cin >> temp;

        if (std::regex_match(rawInput, matches, INPUT_PATTERN) == true) 
        {
            performAction(matches);
        }
        else
        {
            std::cout << "* error" << std::endl;
        }
    }
}

void ProcessManagerUI::performAction(std::cmatch& matches)
{
    try
    {
        std::string first = matches[1].str(), second = matches[2].str(), third = matches[3].str();
        if (first == "in" && second == "" && third == "")
        {
            manager.init();
        }
        else if (first == "to" && second == "" && third == "")
        {
            manager.timeout();
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
            std::cout << "* error" << std::endl;
        }
    }
    catch(...)
    {
        std::cout << "* error" << std::endl;
    }
}