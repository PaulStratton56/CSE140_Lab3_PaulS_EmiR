#ifndef FIELDS_H
#define FIELDS_H

#include <string>
#include <vector>

class Field{
public:


protected:

};

class RField: public Field{
public:
    RField(int* binaryCode){
        
    }

    void printInfo(){

    }

private:
    string operation;
    int rs1, rs2, rd, func3, func7;


};

class IField: public Field{
public:
    IField(int* binaryCode){

    }

    void printInfo(){

    }

private:
    string operation;
    int rs1, rd, imm;

};

class SField: public Field{
public:
    SField(int* binaryCode){

    }

    void printInfo(){

    }

private:
    string operation;
    int rs1, rd, imm;

};

class SBField: public Field{
public:
    SBField(int* binaryCode){

    }

    void printInfo(){

    }

private:
    string operation;
    int rs1, rd, imm;

};

class UJField: public Field{
public:
    UJField(int* binaryCode){

    }

    void printInfo(){

    }

private:
    string operation;
    int rd, imm;

};

#endif
