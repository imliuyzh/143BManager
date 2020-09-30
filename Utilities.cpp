#include "Utilities.h"

void writeOutput(std::string& output, bool createFile=false)
{
    std::fstream fileStream;
    if (createFile)
    {
        fileStream.open("output.txt", std::ios::out|std::ios::trunc);
    }
    else
    {
        fileStream.open("output.txt", std::ios::out|std::ios::app);
    }
    fileStream << output;
    fileStream.close();
}