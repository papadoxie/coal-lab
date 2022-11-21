#include "../include/Cleanup.h"
#include <stdlib.h>

void cleanup(Requirements *reqs)
{
    destroy(reqs->computationTable);
    reqs->computationTable = NULL;
    destroy(reqs->destinationTable);
    reqs->destinationTable = NULL;
    destroy(reqs->jumpTable);
    reqs->jumpTable = NULL;

    fclose(reqs->inputFile);
    fclose(reqs->outputFile);
    
    free(reqs);
}