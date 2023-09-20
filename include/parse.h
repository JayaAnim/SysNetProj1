#ifndef PARSE_H
#define PARSE_H

#include "param.h"

class Parse : public Param {
	public:
		// Runs parser returns true if successful
		bool run();
		// Grabs argument starting at index pos 
		char* grabArg(char input[], int pos, int len);
		// Returns length of argument (stops at spaces, special characters, or end of string)
		int getArgLen(char input[], int pos);
		// Checks if special character format is correct, returns true if correct
		bool checkSpecialChar(char input[], int pos);
};


#endif
