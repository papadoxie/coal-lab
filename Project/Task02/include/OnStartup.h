#pragma once

#include "HashMap.h"
#include <stdio.h>

typedef struct _requirements
{
    FILE *inputFile;
    FILE *outputFile;
    HashMap *destinationTable;
    HashMap *computationTable;
    HashMap *jumpTable;
    HashMap *symbolTable;

} Requirements;

Requirements *onStartup(int argc, char *argv[]);
int argumentCheck(int argc, char *argv[]);
void initLookupTables();
