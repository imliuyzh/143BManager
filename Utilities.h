#ifndef UTILITIES_H
#define UTILITIES_H

#include <fstream>

/**
 * Output the result of the commands to the file "output.txt."
 * @param output an int representing the next process will be run, -1 if there is an error
 * @param newSequence a bool indicating whether a new set of command sequence will begin
 * @param firstSequence a bool indicating if the current command is from the first line of the input file
 */ 
void writeOutput(int output, bool newSequence, bool firstSequence);

#endif