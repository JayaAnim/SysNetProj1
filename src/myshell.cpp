#include <iostream>
#include "../include/parse.h"
#include "../include/run.h"

#include "../include/utils.h"

int main(int argc, char* argv[]) {
    
    listDir();    
    /*
    bool debug = false;
    if (argc >= 2) {
        if (strcmp(argv[1], "-Debug") == 0) {
            debug = true;
        } else {
            std::cout << "[ERROR] Invalid command: Options are ./myshell [-Debug]" << std::endl;
            return 0;
        }
    }
    
    Parse* parser = new Parse();
    while (true) {
        if (!parser->parse()) {
            break;
        }
        if (debug) {
            parser->getParams()->printParams();
        }
    }

    return 1;
    */



    /*
	std::cout << "Program starting" << std::endl;	
	int status;
	pid_t pid = -1;
	Parse* parser = nullptr;
	do {
		if (parser != nullptr) {
			delete parser;
		}
		parser = new Parse();

		if(!parser->run()) {
			break;
		}

		pid = fork();

		// Child Process
		if (pid == 0) {
			Run run;
			run.runCommand(parser);
		}

	} while (parser->getBackground() || waitpid(pid, &status, 0) > 0);
	
	delete parser;

    */
}
