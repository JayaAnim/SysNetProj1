#include <iostream>
#include <cstring>
#include <unistd.h>
#include "../include/parse.h"
#include "../include/handler.h"

Handler::Handler() {
}

int Handler::run(Param params) {
    params.printParams();
    return 0;
}

int Handler::list() {
    return 0;
}

int Handler::cat() {
    return 0;
}

int Handler::program(char* program) {
    return 0;
}
