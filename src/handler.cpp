/*
This program is a functioning shell for file management

@author Chase Lamkin
@author Caleb Shafer
@date 9/24/2023
@info Course COP4634
*/

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include "../include/param.h"
#include "../include/handler.h"


#define MAXARGS 32

Handler::Handler() {
}

int Handler::execute(Param params) {

    if (params.getOutputRedirect() != nullptr) {
        freopen(params.getOutputRedirect(), "w", stdout);
    }

    if (params.getInputRedirect() != nullptr) {
        freopen(params.getInputRedirect(), "r", stdin);
    }     

    return execvp(params.getArgumentVector()[0], params.getArgumentVector());
}

int Handler::handleDir(Param params) {
    if (params.getArgumentCount() == 1) {
        const char *home_dir = getenv("HOME");
        if (home_dir != nullptr) {
            std::cout << "Home directory not found" << std::endl;
            return -1;
        }
        return chdir(home_dir);
    }
    else if (params.getArgumentCount() == 2) {
        if (chdir(params.getArgumentVector()[1]) != 0) {
            std::cout << params.getArgumentVector()[1] << " is not a valid directory" << std::endl;
            return -1;
        }
        return 1;
    }
    else {
        std::cout << "Not a valid directory, use: cd [relative path | absolute path]" << std::endl;
        return -1;
    }
}
