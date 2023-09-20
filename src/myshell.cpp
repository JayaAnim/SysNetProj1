#include <iostream>
#include "../include/parse.h"

int main() {
	std::cout << "Program starting" << std::endl;	
	Parse* parser = new Parse();
	parser->run();
	while (parser->run());
	delete parser;
}
