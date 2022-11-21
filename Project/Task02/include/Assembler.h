#pragma once

#include <stdio.h>
#include "HashMap.h"

/** Assembles the given assembly line by line
 * @param inputFile .asm file
 * @param outputFile .hack file
 * @param destinationTable Lookup table for destination operand
 * @param computationTable Lookup table for computation operand
 * @param jumpTable Lookup table for jump operand
*/
int assemble(FILE *inputFile,
             FILE *outputFile,
             HashMap *destinationTable,
             HashMap *computationTable,
             HashMap *jumpTable,
             HashMap *symbolTable);




int errorHandler(int lineNumber, unsigned char ERROR); //Handle errors
