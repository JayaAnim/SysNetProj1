/*
This program is a functioning shell for file management

@author Chase Lamkin
@author Caleb Shafer
@date 9/24/2023
@info Course COP4634
*/

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

Param::Param(const Param &other) {

    if (other.getInputRedirect() != nullptr) {
        this->inputRedirect = strdup(other.getInputRedirect());
    } else {
        this->inputRedirect = nullptr;
    }

    if (other.getOutputRedirect() != nullptr) {
        this->outputRedirect = strdup(other.getOutputRedirect());
    } else {
        this->outputRedirect = nullptr;
    }
    

    this->background = other.getBackground();

    this->argumentCount = other.getArgumentCount();
    for (int i = 0; i < this->argumentCount; ++i) {
        this->argumentVector[i] = strdup(other.getArgumentVector()[i]);
    }

    for (int i = this->argumentCount; i < 32; ++i) {
        this->argumentVector[i] = nullptr;
    }

}

Param::~Param() {
	if (inputRedirect != nullptr) {
		 delete[] inputRedirect;
		 inputRedirect = nullptr;
	}
	if (outputRedirect != nullptr) {
		delete[] outputRedirect;
		outputRedirect = nullptr;
	}
    for (int i = 0; i < argumentCount; i++) {
		if (argumentVector[i] != nullptr) {
			delete[] argumentVector[i];
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

char* Param::getInputRedirect() const {
    return inputRedirect;
}

void Param::setInputRedirect(char* input) {
	if (inputRedirect != nullptr) delete[] inputRedirect;
    inputRedirect = (input ? strdup(input) : nullptr);
}

char* Param::getOutputRedirect() const {
    return outputRedirect;
}

void Param::setOutputRedirect(char* output) {
    if (outputRedirect != nullptr) delete[] outputRedirect;
    outputRedirect = (output ? strdup(output) : nullptr);
}

void Param::setBackground(int isBackground) {
    this->background = isBackground;
}

int Param::getBackground() const {
    return this->background;
}

int Param::getArgumentCount() const {
    return this->argumentCount;
}

char** Param::getArgumentVector() const {
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
