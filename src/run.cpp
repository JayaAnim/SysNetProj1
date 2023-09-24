#include <iostream>
#include <cstring>
#include <unistd.h>
#include "../include/parse.h"
#include "../include/run.h"

void Run::runCommand(Parse* parser) {

    if (parser->getInputRedirect() != NULL) {
        freopen(parser->getInputRedirect(), "r", stdin);
    }
    if (parser->getOutputRedirect() != NULL) {
        freopen(parser->getOutputRedirect(), "w", stdout);
    }

    char* args[parser->getArgumentCount()+1];
    for (int i=0; i < parser->getArgumentCount(); i++) {
        args[i] = parser->getArguments()[i];
    }
    args[parser->getArgumentCount()] = nullptr;

    execvp(args[0], args);

    std::cout << "Error: Program FAILED\n";
}
