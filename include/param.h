#ifndef PARAM_H
#define PARAM_H

#define MAXARGS 32
/* class to hold input data */
/* feel free to add missing constructor, destructor, and getter/setter functions */

class Param {
	private:
		char *inputRedirect; /* file name or NULL */
		char *outputRedirect; /* file name or NULL */
		int background; /* either 0 (false) or 1 (true) */
		int argumentCount; /* number of tokens in argument vector */
		char *argumentVector[MAXARGS]; /* array of arguments */
	public:
		Param();
        Param(const Param &other);
		~Param();
		//Prints param object
		void printParams();
		//getters and setters
		char* getInputRedirect() const;
		void setInputRedirect(char* input);
		char* getOutputRedirect() const;
		void setOutputRedirect(char* output);
		int setBackground(int isBackground);
		int getBackground() const;
		int getArgumentCount() const;
		char** getArgumentVector() const;
		bool addArgument(char* arg);
		char** getArguments() const;
};

#endif
