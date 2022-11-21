#pragma once

void atobstr(char *buf);                             //Convert any string to binary string
void removeComment(char *buf, unsigned char *ERROR); //Remove comments from the input
int isEmpty(char *buf);                              //Check if string is empty
int isInt(const char *buf);                                //Check if string is an integer string
void stripSpaces(char *buf);                         //Strip whitespace from the input
int isLabel(char *buf);                                       //Check if string is a Label