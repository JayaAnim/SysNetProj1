#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "../include/utils.h"

char* listDir() {
    long path_max;

    // Use pathconf to retrieve the value of _PC_PATH_MAX
    path_max = pathconf(".", _PC_PATH_MAX);     

    char* buf = new char[path_max];
    getcwd(buf, sizeof(buf));

    return nullptr;
}
