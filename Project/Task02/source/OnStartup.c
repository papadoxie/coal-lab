#include "../include/OnStartup.h"
#include "../include/Lookups.h"
#include <stdlib.h>
#include <string.h>

Requirements *onStartup(int argc, char *argv[])
{
    Requirements *requirements = malloc(sizeof(Requirements));

    int input = argumentCheck(argc, argv);

    if (input == -1)
    {
        return NULL;
    }

    if (input == 1)
    {
        requirements->inputFile = fopen(argv[2], "r");
        requirements->outputFile = fopen("a.hack", "w+");
    }

    if (input == 2)
    {
        requirements->inputFile = fopen(argv[2], "r");
        requirements->outputFile = fopen(argv[4], "w");
    }

    if (requirements->inputFile == NULL)
    {
        printf("File %s does not exist\n", argv[2]);
        return NULL;
    }

    initLookupTables();
    requirements->computationTable = computationTable;
    requirements->destinationTable = destinationTable;
    requirements->jumpTable = jumpTable;
    requirements->symbolTable = symbolTable;

    return requirements;
}

int argumentCheck(int argc, char *argv[])
{
    char errorMsg[] = "Usage:\n./assembler -i <input file> -o <output file>";

    if (argc < 3 || argc == 4 || argc > 5)
    {
        puts(errorMsg);
        return -1;
    }

    if (argc == 3)
    {
        if (!strcmp(argv[2], "-i"))
        {
            puts(errorMsg);
            return -1;
        }
        return 1;
    }

    if (argc == 5)
    {
        if (!strcmp(argv[2], "-i"))
        {
            puts(errorMsg);
            return -1;
        }

        if (!strcmp(argv[4], "-o"))
        {
            puts(errorMsg);
            return -1;
        }

        return 2;
    }

    return -1;
}

void initLookupTables()
{
    initComputationTable();
    initJumpTable();
    initDestinationTable();
    initSymbolTable();
}