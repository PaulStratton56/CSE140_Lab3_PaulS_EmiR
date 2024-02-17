#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "fields.h"

class Instruction{
public:
    Instruction(string Binary);     //Constructor
    ~Instruction();                 //Destructor

    void printInfo();               //Printing Information

private:
    string binaryText;
    int* binary = new int[32];
    Field* info;
    void processBinaryText();       //Convert the Binary 



};


#endif