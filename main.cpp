#include "ProcessManagerUI.h"

/**
 * Create a REPL loop to evaluate commands from the input file.
 * @param argc the total number of arguments provided to the program
 * @param argv an array of string listing the arguments for this program
 * @return 0
 */
int main(int argc, char** argv)
{
    if (argc == 2)
    {
        ProcessManagerUI ui;
        ui.getInput(argv[1]);
    }
    return 0;
}