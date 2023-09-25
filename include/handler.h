#ifndef HANDLER_H
#define HANDLER_H

#include "param.h"

class Handler {
	public:
        Handler();
        int run(Param params);
        int list(char* outputRedirect);
        int cat(char* inputFile = nullptr, char* inputRedirect = nullptr);
        int grep(bool printLines, char* word, char* file);
        int program(char* program);
    private:
};


#endif
