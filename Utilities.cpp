#include "Utilities.h"

void writeOutput(int output, bool newSequence=false, bool firstSequence=false)
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