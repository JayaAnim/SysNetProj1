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
#include <signal.h>
#include "../include/parse.h"
#include "../include/handler.h"


int main(int argc, char* argv[]) {

    //Ensures program is started only with ./myshell [-Debug]
    bool debug = false;
    if (argc >= 2) {
        if (strcmp(argv[1], "-Debug") == 0) {
            debug = true;
        } else {
            std::cout << "[ERROR] Invalid command: Options are ./myshell [-Debug]" << std::endl;
            return 0;
        }
    }

    //Parser to parse command line
    Parse* parser = new Parse();
    while (true) {
        std::cout << "Ready for new input" << std::endl;
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
            runner->handleDir(*parser->getParams());
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
                int res = runner->execute(*parser->getParams());
                delete runner;
                exit(res);

            //If not a background process wait for child processes to complete
            } else if (!backgroundProcess) {

                int status;
                waitpid(pid, &status, 0);
            }
        }
    }


    int status;
    pid_t terminated_pid;
    std::cout << "Killing child processes" << std::endl;
    while ((terminated_pid = wait(&status)) > 0) {
        kill(terminated_pid, SIGQUIT);
    }


    return 0;

}
