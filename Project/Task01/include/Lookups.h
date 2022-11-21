#pragma once

#include "HashMap.h"

extern HashMap *destinationTable;
extern HashMap *computationTable;
extern HashMap *jumpTable;

void initDestinationTable();
void initComputationTable();
void initJumpTable();