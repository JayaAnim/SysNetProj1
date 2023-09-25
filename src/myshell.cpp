/*
This program is a functioning shell for file management

@author Chase Lamkin
@author Caleb Shafer
@date 9/24/2023
@info Course COP4634
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/parse.h"
#include "../include/handler.h"


int main(int argc, char* argv[]) {

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
        
        bool backgroundProcess = parser->getParams()->getBackground();

        pid_t pid = fork();

        if (pid < 0) {

            perror("Fork failed");
            exit(1);

        } else if (pid == 0) {

            Handler* runner = new Handler();
            exit(runner->run(*parser->getParams()));

        } else if (!backgroundProcess) {

            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                std::cout << "Child process exited with status " << WEXITSTATUS(status) << std::endl;
            }
        }
    }

    while (wait(NULL) > 0) {}


    return 1;

}
