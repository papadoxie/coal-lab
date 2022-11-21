#pragma once

#include "HashMap.h"

extern HashMap *destinationTable;
extern HashMap *computationTable;
extern HashMap *jumpTable;
extern HashMap *symbolTable;

void initDestinationTable();
void initComputationTable();
void initJumpTable();
void initSymbolTable();
