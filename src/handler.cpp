#include <iostream>
#include <cstring>
#include <unistd.h>
#include "../include/param.h"
#include "../include/handler.h"

Handler::Handler() {
}

int Handler::run(Param params) {
    if (params.getOutputRedirect() != nullptr) {

    }

    if (params.getInputRedirect() != nullptr) {

    }
    return 0;
    /*
    if (params.getArgumentCount() >= 1 && strcmp(params.getArgumentVector()[0], "ls") == 0) {

        //run list function, ensure -l is there, check if output file specified, throw error for any other arguments added
        if (params.getArgumentCount() == 2 && strcmp(params.getArgumentVector()[1], "-l") == 0) {
            return this->list(params.getOutputRedirect());
        } else {
            return -1;     
        }

    } else if (params.getArgumentCount() >= 1 && strcmp(params.getArgumentVector()[0], "cat") == 0) {

        //run cat function, ensure input file specified, differentiate between running cat on entire program or a specific file
        if (params.getArgumentCount() == 1 && params.getInputRedirect() != nullptr) {
            return this->cat(nullptr, params.getInputRedirect()); 
        } else if (params.getArgumentCount() == 2) {
            return this->cat(params.getArgumentVector()[1], nullptr); 
        } else {
            return -1;
        }

    } else if (params.getArgumentCount() > 1 && strcmp(params.getArgumentVector()[0], "grep") == 0) {
        //run grep function, check for -i flag (to differentiate between printing lines), ensure word is specified, ensure file is specified
        return -1;
    } else if (params.getArgumentCount() > 1 && params.getArgumentVector()[0][0] == '.') {
        //run function specified 
        return -1;
    }
    return 1;
    */
}

int Handler::list(char* outputRedirect) {
    if (outputRedirect != nullptr) { 
        size_t nameSize = sizeof(outputRedirect);
        char* fileName = new char[nameSize + 1];
        strcpy(fileName, outputRedirect);
        FILE* outputFile = freopen(fileName, "w", stdout);

        if (outputFile == NULL) {
            return -1;
        }
    }

    int res = execlp("ls", "ls", "-l", (char*)NULL);

    return res;
}

int Handler::cat(char* inputFile, char* inputRedirect) {
    if (inputFile != nullptr) {
        int res = execlp("cat", "cat", inputFile, (char*)NULL);
        return res;
    } else if (inputRedirect != nullptr && strcmp(inputRedirect, "myshell.cpp") == 0) {
        int res = execlp("cat", "cat", "src/myshell.cpp", (char*)NULL);       
        return res;
    }
    return -1;
}

int Handler::grep(bool printLines, char* word, char* file) {
    return 0;
}

int Handler::program(char* program) {
    return 0;
}
