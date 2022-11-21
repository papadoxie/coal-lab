#include "../include/Assembler.h"
#include <string.h>
#include <stdlib.h>

unsigned char ERROR = 0;

int assemble(FILE *inputFile,
             FILE *outputFile,
             HashMap *destinationTable,
             HashMap *computationTable,
             HashMap *jumpTable)
{
    char buf[255];      //Input buffer
    int lineNumber = 0; //Current line number

    while (fgets(buf, 255, inputFile) != NULL) //Loop until end of file
    {
        lineNumber++;

        stripSpaces(buf);
        removeComment(buf);

        if (isEmpty(buf))
        {
            fflush(inputFile);
            memset(buf, 0, 255);
            continue;
        }

        parseInstruction(buf, destinationTable, computationTable, jumpTable);

        if (ERROR)
        {
            freopen(NULL, "w", outputFile);
            return errorHandler(lineNumber);
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

void removeComment(char *buf)
{
    if (strchr(buf, '/') && *(strchr(buf, '/')+1) == '/')
    {
        *strchr(buf, '/') = 0;
        return;
    }
    if (strchr(buf, '/'))
    {
        ERROR = 1;
    }
    return;
}

int isEmpty(char *buf)
{
    if (strlen(buf) <= 2 && (buf[1] == 0 || buf[1] == '\n'))
    {
        return 1;
    }
    return 0;
}

void parseInstruction(char *buf,
                      HashMap *destinationTable,
                      HashMap *computationTable,
                      HashMap *jumpTable)
{
    if (buf[0] == '@')
    {
        aInstruction(buf);
        return;
    }

    cInstruction(buf, destinationTable, computationTable, jumpTable);
}

void aInstruction(char *buf)
{
    char *minbuf = strtok(buf, "@");
    atobstr(minbuf);
    strncpy(buf, minbuf, 255);
}

void cInstruction(char *buf,
                  HashMap *destinationTable,
                  HashMap *computationTable,
                  HashMap *jumpTable)
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
            ERROR = 4;
            return;
        }

        strcat(retbuf, value);
        value = NULL;

        value = parseDestination(token1, destinationTable);
        if (value == NULL)
        {
            ERROR = 3;
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
            ERROR = 5;
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
            ERROR = 4;
            return;
        }

        strcat(retbuf, value);
        value = NULL;

        strcat(retbuf, "000");

        value = parseJump(token2, jumpTable);
        if (value == NULL)
        {
            ERROR = 5;
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

void stripSpaces(char *buf)
{
    char *minbuf = strtok(buf, " ");
    char retbuf[255];
    memset(retbuf, 0, 255);

    while (!(minbuf == NULL))
    {
        strcat(retbuf, minbuf);
        minbuf = strtok(NULL, " ");
    }

    memset(buf, 0, 255);
    strncpy(buf, retbuf, 255);

    if (strchr(buf, '\n')) //Strip newline character
    {
        *strchr(buf, '\n') = '\0';
    }

    if (strchr(buf, 13)) //Strip carriage return character
    {
        *strchr(buf, 13) = 0;
    }

    if (strchr(buf, 9)) //Strip horizontal tab character
    {
        *strchr(buf, 9) = 0;
    }
}

void atobstr(char *buf)
{
    int integer = atoi(buf);
    memset(buf, 0, strlen(buf));

    strcat(buf, "0");

    for (int i = 14; i >= 0; i--)
    {
        int k = integer >> i;
        if (k & 1)
        {
            strcat(buf, "1");
            continue;
        }
        strcat(buf, "0");
    }

    strcat(buf, "\n");
}

int errorHandler(int lineNumber)
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
    default:
        return 0;
    }
}
