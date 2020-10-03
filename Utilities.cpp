#include "Utilities.h"

// Please read the comments in the header file to understand each function.
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