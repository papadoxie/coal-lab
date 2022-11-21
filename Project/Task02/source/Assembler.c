#include "../include/Assembler.h"
#include "../include/Helper.h"
#include "../include/FirstPass.h"
#include "../include/SecondPass.h"
#include <string.h>
#include <stdlib.h>

int assemble(FILE *inputFile,
             FILE *outputFile,
             HashMap *destinationTable,
             HashMap *computationTable,
             HashMap *jumpTable,
             HashMap *symbolTable)
{
    unsigned char ERROR = 0;

    firstPass(inputFile, symbolTable, &ERROR);

    errorHandler(secondPass(inputFile, 
                            outputFile, 
                            destinationTable,
                            computationTable,
                            jumpTable,
                            symbolTable,
                            &ERROR), ERROR);
    
    return 0;
}

int errorHandler(int lineNumber, unsigned char ERROR)
{
    switch (ERROR)
    {
    case 1:
        printf("Invalid Comment Syntax at Line %d\n", lineNumber);
        return ERROR;
    case 2:
        printf("Incomplete Destination = Computation Instruction at Line %d\n", lineNumber);
        return ERROR;
    case 3:
        printf("Invalid Destination at Line %d\n", lineNumber);
        return ERROR;
    case 4:
        printf("Invalid Computation at Line %d\n", lineNumber);
        return ERROR;
    case 5:
        printf("Invalid Jump at Line %d\n", lineNumber);
        return ERROR;
    case 6:
        printf("Invalid C Instruction at Line %d\n", lineNumber);
        return ERROR;
    case 7:
        printf("Duplicate Jump Symbol Found at Line %d\n", lineNumber);
        return ERROR;
    case 8:
        printf("Invalid A Instruction at %d\n", lineNumber);
        return ERROR;
    default:
        return 0;
    }
}
