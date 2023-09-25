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

        //Parse arguments, if error end program
        if (!parser->parse()) {
            break;
        }
        
        //If debug is true print params
        if (debug) {
            parser->getParams()->printParams();
        }
        

        //If change in directory, do it in parent process to affect current shell
        if (strcmp(parser->getParams()->getArgumentVector()[0], "cd") == 0) {

            Handler* runner = new Handler();
            runner->run(*parser->getParams());
            delete runner;

        }
        else {

            //Check if background process needs to be made
            bool backgroundProcess = parser->getParams()->getBackground();

            //Create child process
            pid_t pid = fork();

            //If error creating fork end process
            if (pid < 0) {

                perror("Fork failed");
                exit(1);

            //If child process execute commands given
            } else if (pid == 0) {

                Handler* runner = new Handler();
                int res = runner->run(*parser->getParams());
                delete runner;
                exit(res);

            //If not a background process wait for child processes to complete
            } else if (!backgroundProcess) {

                int status;
                waitpid(pid, &status, 0);
            }
        }
    }

    while (wait(NULL) > 0) {}


    return 1;

}
