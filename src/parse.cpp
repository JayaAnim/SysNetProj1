/*
This program is a functioning shell for file management

@author Chase Lamkin
@author Caleb Shafer
@date 9/24/2023
@info Course COP4634
*/

#include <iostream>
#include <cstring>
#include "../include/parse.h"
#include "../include/param.h"

#define MAXARGS 32


Parse::Parse() {
    this->params = nullptr;
}

bool Parse::parse() {
    //Ensures fresh Param object container exists
    this->cleanParams();

    //Keeps track of # of arguments parsed
    int argCount = 0;

    //Gets argument input from user
    const int BUFFER_SIZE = 300;
    char input[BUFFER_SIZE];
	std::cout << "Please enter your command: " << std::endl;
    std::cin.getline(input, BUFFER_SIZE);

	int strlen = std::cin.gcount();
	
	for (int i = 0; input[i] != '\0' && i < strlen; ++i) {
        //Ensures max of 32 arguments
        if (++argCount > 32) return false;

        //Checks for tab, returns false if tab not found
        if (input[i] == '\\') {

            if (checkSpecialChar(input, ++i)) {
                ++i;
            } 
            else {
                std::cout << "[ERROR] Exiting because of invalid special char" << std::endl;
                return false;
            }
        } 

        //Skips parsing spaces between arguements
        else if (input[i] == ' ') {
			// pass
        } 

        //Checks for background process flag
        else if (input[i] == '&') {
			this->params->setBackground(1);	
		} 

        //Checks for output file argument
        else if (input[i] == '>') {
			++i;	
			int len = getArgLen(input, i);
			char* arg = grabArg(input, i, len);
			i = i + len - 1;
			if (std::strcmp(arg, " ") == 0 || std::strcmp(arg, "\0") == 0 || std::strcmp(arg, "\\") == 0) {
				std::cout << "[ERROR] Exiting because of invalid filename, to specify file name use [> | <]filename, do not use spaces" << std::endl;
				return false;
			}
			this->params->setOutputRedirect(arg);
		} 

        //Checks for input file argument
        else if (input[i] == '<') {
			++i;	
			int len = getArgLen(input, i);
			char* arg = grabArg(input, i, len);
			i = i + len - 1;
			if (std::strcmp(arg, " ") == 0 || std::strcmp(arg, "\0") == 0 || std::strcmp(arg, "\\") == 0) {
				std::cout << "[ERROR] Exiting because of invalid filename, to specify file name use [> | <]filename, do not use spaces" << std::endl;
				return false;
			}
			this->params->setInputRedirect(arg);
		} 

        //If none of the above, word must be argument, adds word to argument array
        else {
			int len = getArgLen(input, i);
			char* arg = grabArg(input, i, len);
			i = i + len - 1;
			if (std::strcmp(arg, "exit") == 0) return false;
			this->params->addArgument(arg);
		}

	}

	return true;

}

void Parse::cleanParams() {
    if (this->params != nullptr) delete this->params;
    this->params = new Param();
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
	for (; input[pos] != '\0' && input[pos] != '\\' && input[pos] != ' ' && input[pos] != '\n'; ++pos);
	return pos - start;
}

bool Parse::checkSpecialChar(char input[], int pos) {
	return input[pos] == 't' || input[pos] == ' ';
}

Param* Parse::getParams() {
    return this->params;
}

Parse::~Parse() {
    if (this->params != nullptr) delete this->params;
}


