#include "../include/SecondPass.h"
#include "../include/Helper.h"
#include <string.h>
#include <stdlib.h>

int variablePosition = 16;

int secondPass(FILE *inputFile,
               FILE *outputFile,
               HashMap *destinationTable,
               HashMap *computationTable,
               HashMap *jumpTable,
               HashMap *symbolTable,
               unsigned char *ERROR)
{
    char buf[255];      //Input buffer
    int lineNumber = 0; //Current line number

    while (fgets(buf, 255, inputFile) != NULL) //Loop until end of file
    {
        lineNumber++;

        stripSpaces(buf);
        removeComment(buf, ERROR);

        if (isEmpty(buf) || isLabel(buf))
        {
            fflush(inputFile);
            memset(buf, 0, 255);
            continue;
        }

        parseInstruction(buf,
                         destinationTable,
                         computationTable,
                         jumpTable,
                         symbolTable,
                         ERROR);

        if (*ERROR)
        {
            freopen(NULL, "w", outputFile);
            return lineNumber;
        }

        if (!(strlen(buf) == 2))
        {
            fputs(buf, outputFile);
        }

        fflush(inputFile);
        memset(buf, 0, 255);
    }

    return 0;
}

void parseInstruction(char *buf,
                      HashMap *destinationTable,
                      HashMap *computationTable,
                      HashMap *jumpTable,
                      HashMap *symbolTable,
                      unsigned char *ERROR)
{
    if (buf[0] == '@')
    {
        aInstruction(buf, symbolTable, ERROR);
        return;
    }

    cInstruction(buf, destinationTable, computationTable, jumpTable, ERROR);
}

void aInstruction(char *buf, HashMap *symbolTable, unsigned char *ERROR)
{
    char *minbuf = strtok(buf, "@");
    char *value = NULL;
    char varString[25]; //String represenation of variable
    char retbuf[255];

    memset(retbuf, 0, 255);
    strcat(retbuf, "0");

    if (isInt(minbuf))
    {
        atobstr(minbuf);
        strcat(retbuf, minbuf);
        strcat(retbuf, "\n");
        strcpy(buf, retbuf);
        return;
    }

    value = get(symbolTable, minbuf);
    if (value == NULL)
    {
        sprintf(varString, "%d", variablePosition);
        variablePosition++;
        atobstr(varString);
        insertPair(symbolTable, minbuf, varString);
        value = NULL;
    }

    value = get(symbolTable, minbuf);
    memset(buf, 0, 255);
    strcat(buf, "0");
    strcat(buf, value);
    strcat(buf, "\n");
}

void cInstruction(char *buf,
                  HashMap *destinationTable,
                  HashMap *computationTable,
                  HashMap *jumpTable,
                  unsigned char *ERROR)
{
    char bufcpy[255]; //Copy of original buffer
    strcpy(bufcpy, buf);

    //Tokenize the copied buffer
    char *token1 = strtok(bufcpy, "=;");
    char *token2 = strtok(NULL, "=;");
    char *token3 = strtok(NULL, "=;");

    char retbuf[255];       //Buffer to be returned
    memset(retbuf, 0, 255); //Clear the return buffer
    strcat(retbuf, "111");  //Append starting bits of C instruction

    char *value = NULL; //Temp value to store returned value from hash table

    if (!(strchr(buf, '=') == NULL))
    {
        value = parseComputation(token2, computationTable);
        if (value == NULL)
        {
            *ERROR = 4;
            return;
        }

        strcat(retbuf, value);
        value = NULL;

        value = parseDestination(token1, destinationTable);
        if (value == NULL)
        {
            *ERROR = 3;
            return;
        }

        strcat(retbuf, value);
        value = NULL;

        if (strchr(buf, ';') == NULL)
        {
            token3 = "\0";
        }

        value = parseJump(token3, jumpTable);
        if (value == NULL)
        {
            *ERROR = 5;
            return;
        }

        strcat(retbuf, value);
        value = NULL;

        strcat(retbuf, "\n");
        strncpy(buf, retbuf, 255);

        return;
    }

    if (!(strchr(buf, ';') == NULL))
    {
        value = parseComputation(token1, computationTable);
        if (value == NULL)
        {
            *ERROR = 4;
            return;
        }

        strcat(retbuf, value);
        value = NULL;

        strcat(retbuf, "000");

        value = parseJump(token2, jumpTable);
        if (value == NULL)
        {
            *ERROR = 5;
            return;
        }

        strcat(retbuf, value);
        value = NULL;

        strcat(retbuf, "\n");
        strncpy(buf, retbuf, 255);

        return;
    }
}

char *parseDestination(char *buf, HashMap *destinationTable)
{
    if (buf == NULL)
    {
        return NULL;
    }
    return get(destinationTable, buf);
}

char *parseComputation(char *buf, HashMap *computationTable)
{
    if (buf == NULL)
    {
        return NULL;
    }
    return get(computationTable, buf);
}

char *parseJump(char *buf, HashMap *jumpTable)
{
    if (buf == NULL)
    {
        return NULL;
    }
    return get(jumpTable, buf);
}
