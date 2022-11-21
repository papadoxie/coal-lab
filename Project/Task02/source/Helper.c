#include "../include/Helper.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void atobstr(char *buf)
{
    int integer = atoi(buf);
   
    memset(buf, 0, strlen(buf));

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
}

void removeComment(char *buf, unsigned char *ERROR)
{
    if (strchr(buf, '/') && *(strchr(buf, '/') + 1) == '/')
    {
        *strchr(buf, '/') = 0;
        return;
    }
    if (strchr(buf, '/'))
    {
        *ERROR = 1;
    }
    return;
}

int isEmpty(char *buf)
{
    if (strlen(buf) < 2 || buf[0] == 0 || buf[0] == '\n')
    {
        return 1;
    }
    return 0;
}

int isInt(const char *buf)
{
    for (int i = 0; i < strlen(buf); i++)
    {
        if (!isdigit(buf[i]))
        {
            return 0;
        }
    }
    return 1;
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

int isLabel(char *buf)
{
    if (buf[0] == '(')
    {
        return 1;
    }
    return 0;
}