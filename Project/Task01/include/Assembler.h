#pragma once

#include <stdio.h>
#include "HashMap.h"

extern unsigned char ERROR;

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
             HashMap *jumpTable);

void removeComment(char *buf);    //Remove comments from the input
int isEmpty(char *buf);           //Ignore Empty lines
void stripSpaces(char *buf);      //Strip whitespace from the input
int errorHandler(int lineNumber); //Handle errors

/** Parse the input for instructions
 * @param buf Input Buffer
 * @param destinationTable Lookup table for destination operand
 * @param computationTable Lookup table for computation operand
 * @param jumpTable Lookup table for jump operand
*/
void parseInstruction(char *buf,
                      HashMap *destinationTable,
                      HashMap *computationTable,
                      HashMap *jumpTable);

//Parse A Instruction
void aInstruction(char *buf);

//Parse C Instruction
void cInstruction(char *buf,
                  HashMap *destinationTable,
                  HashMap *computationTable,
                  HashMap *jumpTable);

char *parseDestination(char *buf, HashMap *destinationTable);
char *parseComputation(char *buf, HashMap *computationTable);
char *parseJump(char *buf, HashMap *jumpTable);

 //Convert any string to binary string
void atobstr(char *buf);
