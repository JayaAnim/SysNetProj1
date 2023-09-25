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
            int res = runner->run(*parser->getParams());
            exit(res);

        } else {

            if (!backgroundProcess) {
                int status;
                waitpid(pid, &status, 0);

                if (WIFEXITED(status)) {
                    std::cout << "Child process exited with status " << WEXITSTATUS(status) << std::endl;
                }
            } 
        }
    }

    while (wait(NULL) > 0) {}


    return 1;

}

        //Check if background process needs to be executed

        //if process needs to be executed in background 

            //create fork

            //in parent process rerun while loop to wait for next command
        
            //in child process pass params to Run so exec can be called for proper command

        //if process needs to be executed in foreground

        //pass params to run Run class so exec can be called for proper command

        //wait for process to complete then continue while loop


    //if process ends, whether through child process error, parent error, or exit being called, ensure all child processes end, and no zombie processes exist

