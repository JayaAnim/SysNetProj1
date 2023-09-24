#include <iostream>
#include <cstring>
#include <unistd.h>
#include "../include/parse.h"
#include "../include/handler.h"

Handler::Handler() {
}

int Handler::run(Param params) {
    if (params.getArgumentCount() > 1 && strcmp(params.getArgumentVector()[0], "ls") == 0) {
        //run list function, ensure -l is there, check if output file specified, throw error for any other arguments added
    } else if (params.getArgumentCount() > 1 && strcmp(params.getArgumentVector()[0], "cat") == 0) {
        //run cat function, ensure input file specified, differentiate between running cat on entire program or a specific file
    } else if (params.getArgumentCount() > 1 && strcmp(params.getArgumentVector()[0], "grep") == 0) {
        //run grep function, check for -i flag (to differentiate between printing lines), ensure word is specified, ensure file is specified
    } else if (params.getArgumentCount() > 1 && params.getArgumentVector()[0][0] == '.') {
        //run function specified 
    }
    return 0;
}

int Handler::list(char* outputRedirect) {
    return 0;
}

int Handler::cat(char* inputFile, char* inputRedirect) {
    return 0;
}

int Handler::grep(bool printLines, char* word, char* file) {
    return 0;
}

int Handler::program(char* program) {
    return 0;
}
