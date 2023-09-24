#ifndef HANDLER_H
#define HANDLER_H

#include "param.h"

class Handler {
	public:
        Handler();
        int run(Param params);
        int list();
        int cat();
        int program(char* program);
    private:
};


#endif
