#ifndef RUN_H
#define RUN_H

#include "parse.h"

class Run {
	public:
		Run(){}

        //  Executes command given from parser
        void runCommand(Parse* parser);
};


#endif
