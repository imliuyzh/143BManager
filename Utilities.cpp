#include "Utilities.h"

/**
 * Output process numbers to "output.txt"
 * @param output an int representing the next process will be run
 * @param newSequence a bool indicating whether a new set of command sequence will begin
 * @param firstSequence a bool indicating whether the processed output should correspond to the first line of the input file
 */ 
void writeOutput(int output, bool newSequence, bool firstSequence)
{
    std::fstream fileStream;
    fileStream.open("output.txt", std::ios::out|std::ios::app);
    if (newSequence)
    {
        if (firstSequence)
        {
            fileStream << output;
        }
        else
        {
            fileStream << std::endl << output;
        }
    }
    else
    {
        fileStream << " " << output;
    }
    fileStream.close();
}