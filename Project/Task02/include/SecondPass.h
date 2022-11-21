#pragma once

#include <stdio.h>
#include "HashMap.h"

extern int variablePosition; //Position of next variable in memory

int secondPass(FILE *inputFile,
               FILE *outputFile,
               HashMap *destinationTable,
               HashMap *computationTable,
               HashMap *jumpTable,
               HashMap *symbolTable,
               unsigned char *ERROR);

/** Parse the input for instructions
 * @param buf Input Buffer
 * @param destinationTable Lookup table for destination operand
 * @param computationTable Lookup table for computation operand
 * @param jumpTable Lookup table for jump operand
 * @param symbolTable Lookup table for symbols
 * @param ERROR Changed if there is an error encountered
*/
void parseInstruction(char *buf,
                      HashMap *destinationTable,
                      HashMap *computationTable,
                      HashMap *jumpTable,
                      HashMap *symbolTable,
                      unsigned char *ERROR);

//Parse A Instruction
void aInstruction(char *buf, HashMap *symbolTable, unsigned char *ERROR);

//Parse C Instruction
void cInstruction(char *buf,
                  HashMap *destinationTable,
                  HashMap *computationTable,
                  HashMap *jumpTable,
                  unsigned char *ERROR);

char *parseDestination(char *buf, HashMap *destinationTable);
char *parseComputation(char *buf, HashMap *computationTable);
char *parseJump(char *buf, HashMap *jumpTable);