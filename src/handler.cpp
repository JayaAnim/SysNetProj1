#include <iostream>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/param.h"
#include "../include/handler.h"


#define MAXARGS 32

Handler::Handler() {
}

int Handler::run(Param params) {
    if (strcmp(params.getArgumentVector()[0], "cd") == 0) {
        if (params.getArgumentCount() == 1) {
            return this->handleDir(nullptr);
        }
        else if (params.getArgumentCount() == 2) {
            return this->handleDir(params.getArgumentVector()[1]); 
        }
        else {
            std::cout << "Not a valid directory, use: cd [relative path | absolute path]" << std::endl;
            return -1;
        }
    }

    if (params.getOutputRedirect() != nullptr) {
        freopen(params.getOutputRedirect(), "w", stdout);
    }

    if (params.getInputRedirect() != nullptr) {
        freopen(params.getInputRedirect(), "r", stdin);
    }     

    return execvp(params.getArgumentVector()[0], params.getArgumentVector());
}

int Handler::handleDir(const char* path) {
    std::cout << "trying to go to directory: " << path << std::endl;
    if (path == nullptr) {
        const char *home_dir = getenv("HOME");
        if (home_dir != nullptr) {
            std::cout << "Home directory not found" << std::endl;
            return -1;
        }
        chdir(home_dir);
    } else {
        if (chdir(path) != 0) {
            std::cout << path << " is not a valid directory" << std::endl;
            return -1;
        }
        return 1;
    }
    return 1;
}
