#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
#include "../include/parse.h"
#include "../include/run.h"

int main() {
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

}
