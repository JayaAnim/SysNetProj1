#include <iostream>
#include <cstring>
#include <unistd.h>
#include "../include/param.h"
#include "../include/handler.h"


#define MAXARGS 32

Handler::Handler() {
}

int Handler::run(Param params) {
    if (params.getOutputRedirect() != nullptr) {
        freopen(params.getOutputRedirect(), "w", stdout);
    }

    if (params.getInputRedirect() != nullptr) {
        freopen(params.getInputRedirect(), "r", stdin);
    }
    
     

    //Ensures no bad special characters exist (i.e \n, \t, etc)
    //char* cmd = strdup(params.getArgumentVector()[0]);
    char* args[MAXARGS]; 
    for (int i = 0; i <= params.getArgumentCount(); ++i) {
        if (i == params.getArgumentCount()) {
            args[i] = (char*)NULL;
        } else {
            args[i] = strdup(params.getArgumentVector()[i]);
        }
    }

    return execvp(params.getArgumentVector()[0], params.getArgumentVector());
}

