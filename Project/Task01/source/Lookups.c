#include "../include/Lookups.h"

#include <stdlib.h>

HashMap *destinationTable = NULL;
HashMap *computationTable = NULL;
HashMap *jumpTable = NULL;

void initDestinationTable()
{
    destinationTable = initMap(8);

    insertPair(destinationTable,    "\0",   "000");
    insertPair(destinationTable,    "M",    "001");
    insertPair(destinationTable,    "D",    "010");
    insertPair(destinationTable,    "MD",   "011");
    insertPair(destinationTable,    "A",    "100");
    insertPair(destinationTable,    "AM",   "101");
    insertPair(destinationTable,    "AD",   "110");
    insertPair(destinationTable,    "AMD",  "111");
}

void initComputationTable()
{
    computationTable = initMap(28);

    insertPair(computationTable,    "0",    "0101010");
    insertPair(computationTable,    "1",    "0111111");
    insertPair(computationTable,    "-1",   "0111010");
    insertPair(computationTable,    "D",    "0001100");
    insertPair(computationTable,    "A",    "0110000");
    insertPair(computationTable,    "!D",   "0001101");
    insertPair(computationTable,    "!A",   "0110001");
    insertPair(computationTable,    "-D",   "0001111");
    insertPair(computationTable,    "-A",   "0110011");
    insertPair(computationTable,    "D+1",  "0011111");
    insertPair(computationTable,    "A+1",  "0110111");
    insertPair(computationTable,    "D-1",  "0001110");
    insertPair(computationTable,    "A-1",  "0110010");
    insertPair(computationTable,    "D+A",  "0000010");
    insertPair(computationTable,    "D-A",  "0010011");
    insertPair(computationTable,    "A-D",  "0000111");
    insertPair(computationTable,    "D&A",  "0000000");
    insertPair(computationTable,    "D|A",  "0010101");
    insertPair(computationTable,    "M",    "1110000");
    insertPair(computationTable,    "!M",   "1110001");
    insertPair(computationTable,    "-M",   "1110011");
    insertPair(computationTable,    "M+1",  "1110111");
    insertPair(computationTable,    "M-1",  "1110010");
    insertPair(computationTable,    "D+M",  "1000010");
    insertPair(computationTable,    "D-M",  "1010011");
    insertPair(computationTable,    "M-D",  "1000111");
    insertPair(computationTable,    "D&M",  "1000000");
    insertPair(computationTable,    "D|M",  "1010101");
}

void initJumpTable()
{
    jumpTable = initMap(8);

    insertPair(jumpTable,    "\0",    "000");
    insertPair(jumpTable,   "JGT",    "001");
    insertPair(jumpTable,   "JEQ",    "010");
    insertPair(jumpTable,   "JGE",    "011");
    insertPair(jumpTable,   "JLT",    "100");
    insertPair(jumpTable,   "JNE",    "101");
    insertPair(jumpTable,   "JLE",    "110");
    insertPair(jumpTable,   "JMP",    "111");
}