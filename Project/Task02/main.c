#include "include/OnStartup.h"
#include "include/Assembler.h"
#include "include/Cleanup.h"

int main(int argc, char *argv[])
{
    Requirements *req = onStartup(argc, argv);
    
    if (req == NULL)
    {
        return 1;
    }

    int exitStatus = assemble(req->inputFile, 
                              req->outputFile,
                              req->destinationTable,
                              req->computationTable,
                              req->jumpTable,
                              req->symbolTable);

    cleanup(req);

    return exitStatus;
}