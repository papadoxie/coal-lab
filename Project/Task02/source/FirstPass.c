#include "../include/FirstPass.h"
#include "../include/Helper.h"
#include <stdlib.h>
#include <string.h>

int lineNumber = 0;

void firstPass(FILE *inputFile, HashMap *symbolTable, unsigned char *ERROR)
{
    char buf[255];

    while (fgets(buf, 255, inputFile) != NULL)
    {
        stripSpaces(buf);
        removeComment(buf, ERROR);

        if (isEmpty(buf))
        {
            fflush(inputFile);
            memset(buf, 0, 255);
            continue;
        }

        lineNumber++;
        parseLabels(buf, symbolTable, ERROR);
        

    }
    fseek(inputFile, 0, SEEK_SET);
}

void parseLabels(char *buf, HashMap *symbolTable, unsigned char *ERROR)
{
    char *startingBracket = strchr(buf, '(');
    char *endingBracket = strchr(buf, ')');
    char *minbuf = NULL;
    char *symbol;
    char binBuf[15];

    if(startingBracket != NULL && endingBracket != NULL)
    {
        minbuf = strtok(buf, "(");
        minbuf[strlen(minbuf)-1] = 0;

        symbol = get(symbolTable, minbuf);

        if(symbol == NULL){
            sprintf(binBuf, "%d", --lineNumber);
            atobstr(binBuf);
            insertPair(symbolTable, minbuf, binBuf);
            return;
        }
        *ERROR = 7;
    }
}