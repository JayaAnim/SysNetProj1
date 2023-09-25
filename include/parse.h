#ifndef PARSE_H
#define PARSE_H

#include "param.h"

class Parse {
	public: 
        Parse();
		// Runs parser returns true if successful
		bool parse();
		// Grabs argument starting at index pos 
		char* grabArg(char input[], int pos, int len);
		// Returns length of argument (stops at spaces, special characters, or end of string)
		int getArgLen(char input[], int pos);
		// Checks if special character format is correct, returns true if correct
		bool checkSpecialChar(char input[], int pos);
        // Makes new params obj if none exists, if params obj exists deletes it and creates fresh params container
        void cleanParams();

        Param* getParams();

        ~Parse();
    private:
        Param* params;
};


#endif
