#ifndef UTILITIES_H
#define UTILITIES_H

#include <fstream>
#include <string>

/**
 * Output process numbers to "output.txt"
 * @param output an int representing the next process will be run
 * @param newSequence a bool indicating whether a new set of command sequence will begin
 * @param firstSequence a bool indicating whether the processed output should correspond to the first line of the input file
 */ 
void writeOutput(int output, bool newSequence=false, bool firstSequence=false);

#endif