#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>
#include <cmath>
#include "fields.h"

using namespace std;

class Instruction{
public:
    Instruction(string Binary){     //Constructor
        cout << "Enter an instruction:" << endl;
        cin >> binaryText;

        binary = processBinaryText();

        /* Compares binary's opcode to each Field's opcode (in decimal form). */
        switch(getOpcode()){
            case(51):
                info = new RField(binary);
                break;
            case(19):
            case(103):
                info = new IField(binary);
                break;
            case(35):
                info = new SField(binary);
                break;
            case(99):
                info = new SBField(binary);
                break;
            case(111):
                info = new UJField(binary);
                break;
            printf("Not a valid case");
            return;
        }
        return;
    }

    ~Instruction(){                 //Destructor
        delete info;
    }

    void printInfo(){               //Printing Information
        info->printInfo();
    }

private:
    string binaryText;              //Given binaryText
    vector<int> binary;             //Make binary vector with 32 ints
    Field* info;                    //Input Field

    vector<int> processBinaryText(){       //Convert binaryText to binary
        vector<int> ans;
        for(int i = 0; i < binaryText.length(); i++){
            ans.push_back((int)(binaryText[i]));
        }

        return ans;
    }

    int getOpcode(){                   //Convert the Opcode Binary to Hex
        int ans = binToInt(binary, {0, 1, 2, 3, 4, 5, 6});
        return ans;
    }

    int binToInt(vector<int> binary, vector<int> indices = {}){
        int result = 0;
        if(indices.size() == 0){
            for(int i = 0; i < binary.size(); i++){
                result += binary[i] * pow(2,i);
            }
        }
        else{
            for(int i = 0; i < indices.size(); i++){
                result += binary[indices[i]] * pow(2,i);
            }
        }
        return result;
    }

    string type;    //Type of Field
};


#endif


/*
    string binToHex(){
        string ans = "";
        int num;
        vector<int> temp_binary = binary;
        vector<int> temp;

        while(temp_binary.size() > 0){
            for(int i = 0; i < 4; i++){
                temp.push_back(temp_binary[i]);
                temp_binary.erase(temp_binary.begin());
            }

            num = binToInt(temp, {0, 1, 2, 3});

            if(num < 10){
                ans += (char)num;
            }else if(num == 10){
                ans += "A";   
            }else if(num == 11){
                ans += "B";
            }else if(num == 12){
                ans += "C";
            }else if(num == 13){
                ans += "D";
            }else if(num == 14){
                ans += "E";
            }else if(num == 15){
                ans += "F";
            }

            temp.clear();
        }

        return ans;
    }
*/