#include <iostream>
#include <cstring>
#include <unistd.h>
#include "../include/parse.h"
#include "../include/run.h"

void Run::runCommand(Parse* parser) {

    if (parser->getParams()->getInputRedirect() != NULL) {
        freopen(parser->getParams()->getInputRedirect(), "r", stdin);
    }
    if (parser->getParams()->getOutputRedirect() != NULL) {
        freopen(parser->getParams()->getOutputRedirect(), "w", stdout);
    }

    char* args[parser->getParams()->getArgumentCount()+1];
    for (int i=0; i < parser->getParams()->getArgumentCount(); i++) {
        args[i] = parser->getParams()->getArguments()[i];
    }
    args[parser->getParams()->getArgumentCount()] = nullptr;

    execvp(args[0], args);

    std::cout << "Error: Program FAILED\n";
}
