#include <iostream>
#include <cstring>
#include "../include/param.h"

#define MAXARGS 32

Param::Param() {
    inputRedirect = nullptr;
    outputRedirect = nullptr;
    background = 0;
    argumentCount = 0;
    for (int i = 0; i < MAXARGS; i++) {
        argumentVector[i] = nullptr;
    }
}

Param::~Param() {
	if (inputRedirect != nullptr) {
		 delete inputRedirect;
		 inputRedirect = nullptr;
	}
	if (outputRedirect != nullptr) {
		delete outputRedirect;
		outputRedirect = nullptr;
	}
    for (int i = 0; i < argumentCount; i++) {
		if (argumentVector[i] != nullptr) {
			delete argumentVector[i];
			argumentVector[i] = nullptr;
		}
    }
}

void Param::printParams() {
    std::cout << "InputRedirect: [" << (inputRedirect != NULL ? inputRedirect : "NULL") << "]" << std::endl;
    std::cout << "OutputRedirect: [" << (outputRedirect != NULL ? outputRedirect : "NULL") << "]" << std::endl;
    std::cout << "Background: [" << background << "]" << std::endl;
    std::cout << "ArgumentCount: [" << argumentCount << "]" << std::endl;
    for (int i = 0; i < argumentCount; i++) {
        std::cout << "ArgumentVector[" << i << "]: [" << argumentVector[i] << "]" << std::endl;
    }
}

char* Param::getInputRedirect() {
    return inputRedirect;
}

void Param::setInputRedirect(char* input) {
	if (inputRedirect != nullptr) {
		delete[] inputRedirect;
	}
    inputRedirect = (input ? strdup(input) : nullptr);
}

char* Param::getOutputRedirect() {
    return outputRedirect;
}

void Param::setOutputRedirect(char* output) {
    delete[] outputRedirect;
    outputRedirect = (output ? strdup(output) : nullptr);
}

int Param::setBackground(int isBackground) {
    background = isBackground;
    return background;
}

int Param::getBackground() {
    return background;
}

int Param::getArgumentCount() {
    return argumentCount;
}

char** Param::getArgumentVector() {
    return (char**)argumentVector;
}

bool Param::addArgument(char* arg) {
    if (argumentCount >= MAXARGS) {
        return false; // Cannot add more arguments, reached the limit
    }
    argumentVector[argumentCount] = strdup(arg);
    argumentCount++;
    return true;
}

char** Param::getArguments() {
	if (argumentCount > 0) return (char**)argumentVector;
	return nullptr;
}


