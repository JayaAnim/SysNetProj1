#ifndef UTILS_H
#define UTILS_H

char* listDir();
void writeToFIle(char* fileName);
char** grep(char* grepWord, char* fileName);
char* catFile(char* fileName);
char* catSource(char* fileName);
bool runSlow();


#endif
