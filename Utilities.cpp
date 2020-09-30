#include "Utilities.h"

void writeOutput(int output, bool createFile=false)
{
    std::fstream fileStream;
    if (createFile)
    {
        fileStream.open("output.txt", std::ios::out|std::ios::trunc);
        fileStream << output;
    }
    else
    {
        fileStream.open("output.txt", std::ios::out|std::ios::app);
        fileStream << " " << output;
    }
    fileStream.close();
}

void writeNewline()
{
    std::fstream fileStream;
    fileStream.open("output.txt", std::ios::out|std::ios::app);
    fileStream << std::endl;
    fileStream.close();
}