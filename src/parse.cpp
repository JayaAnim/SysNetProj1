#include <iostream>
#include <cstring>
#include "../include/parse.h"
#include "../include/param.h"

#define MAXARGS 32

bool Parse::run() {
    const int BUFFER_SIZE = 300;
    char input[BUFFER_SIZE];
    
	std::cout << "Please enter your command: " << std::endl;
    std::cin.getline(input, BUFFER_SIZE);


	int strlen = std::cin.gcount();

	bool debug = false;
	
	for (int i = 0; input[i] != '\0' && i < strlen && getArgumentCount() < 32; ++i) {
		if (input[i] == '\\') {
			if (checkSpecialChar(input, ++i)) {
				++i;
				// valid special char
			} else {
				std::cout << "[ERROR] Exiting because of invalid special char" << std::endl;
				return false;
			}
		} else if (input[i] == ' ') {
			// pass
		} else if (input[i] == '&') {
			setBackground(1);	
		} else if (input[i] == '>') {
			// Spaces not allowed between > and file name
			++i;	
			int len = getArgLen(input, i);
			char* arg = grabArg(input, i, len);
			i = i + len - 1;
			if (std::strcmp(arg, " ") == 0 || std::strcmp(arg, "\0") == 0 || std::strcmp(arg, "\\") == 0) {
				std::cout << "[ERROR] Exiting because of invalid filename, to specify file name use [> | <]filename, do not use spaces" << std::endl;
				return false;
			}
			setOutputRedirect(arg);
		} else if (input[i] == '<') {
			// Spaces not allowed between < and file name
			++i;	
			int len = getArgLen(input, i);
			char* arg = grabArg(input, i, len);
			i = i + len - 1;
			if (std::strcmp(arg, " ") == 0 || std::strcmp(arg, "\0") == 0 || std::strcmp(arg, "\\") == 0) {
				std::cout << "[ERROR] Exiting because of invalid filename, to specify file name use [> | <]filename, do not use spaces" << std::endl;
				return false;
			}
			setInputRedirect(arg);
		} else if (input[i] == '-') {
			++i;	
			int len = getArgLen(input, i);
			char* arg = grabArg(input, i, len);
			i = i + len - 1;
			if (std::strcmp(arg, "-Debug") == 0) {
				debug = true;
			} else {
				std::cout << "[ERROR] Exiting because of invalid flag [ - ], valid flags include: [-Debug]" << std::endl;
				return false;
			}
		} else {
			int len = getArgLen(input, i);
			char* arg = grabArg(input, i, len);
			i = i + len - 1;
			if (std::strcmp(arg, "exit") == 0) return false;
			addArgument(arg);
		}

	//	std::cout << "Arg Count: " << getArgumentCount() << "\nstrlen: " << strlen << "\ni: " << i << std::endl;
	}
	if (debug) printParams();

	return true;

}

char* Parse::grabArg(char input[], int pos, int len) {
	char* arg = new char[len + 1];
	for (int i = 0; i < len; ++i) {
		arg[i] = input[pos];
		++pos;
	}
	arg[len] = '\0';
	return arg;
}

int Parse::getArgLen(char input[], int pos) {
	int start = pos;
	for (; input[pos] != '\0' && input[pos] != '\\' && input[pos] != ' '; ++pos);
	return pos - start;
}

bool Parse::checkSpecialChar(char input[], int pos) {
	return input[pos] == 't' || input[pos] == ' ';
}

