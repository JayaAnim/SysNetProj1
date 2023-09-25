#ifndef HANDLER_H
#define HANDLER_H

#include "param.h"

class Handler {
	public:
        Handler();
        int execute(Param params);
        int handleDir(Param params);
    private:
};


#endif
