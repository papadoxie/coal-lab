#pragma once

#include <stdio.h>
#include "HashMap.h"

extern int lineNumber;

void firstPass(FILE *inputFile, HashMap *symbolTable, unsigned char *ERROR);
void parseLabels(char *buf, HashMap *symbolTable, unsigned char *ERROR);