#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "fields.h"

using namespace std;

/* == binToInt ==
    Input:
        binary: list of binary digits to convert to decimal. Assumes lsb is stored at index 0.
        (optional) indices: if provided, takes binary digits at the provided indices, starting from the index at indices[0].
        
    Output:
        result: integer conversion of the binary digits to decimal. 
        
    Description:
        Takes in binary digits and optional indices to choose from, and returns the value converted to binary in an integer. */
// int binToInt(vector<int> binary, vector<int> indices = {}, bool checkSign = false){
//     int result = 0;
//     if(!checkSign){ // Unsigned conversion
//         if(indices.size() == 0){ //No index provided, use whole vector
//             for(int i = 0; i < binary.size(); i++){
//                 result += binary[i] * pow(2,i);
//             }
//         }
//         else{ //Index provided, pull from indices (not much different)
//             for(int i = 0; i < indices.size(); i++){
//                 result += binary[indices[i]] * pow(2,i);
//             }
//         }
//     }
//     else{ // Signed conversion
//         if(indices.size() == 0){ //No index provided, use whole vector
//             if(binary[binary.size()-1] == 0){ //No sign necessary, convert as normal
//                 for(int i = 0; i < binary.size(); i++){
//                     result += binary[i] * pow(2,i);
//                 }
//             }
//             else{ //Negative, convert inverse and add 1, then make negative
//                 for(int i = 0; i < (binary.size()-1); i++){ //Size-1 to ignore sign bit
//                     result += ((binary[i] + 1) % 2) * pow(2,i); //Flip bits using %2
//                 }
//                 result += 1; //Add 1 (otherwise 1's complement)
//                 result *= -1; //Flip because negative!
//             }
//         }
//         else{ //Index provided, pull from indices (not much different)
//             if(binary[indices[indices.size()-1]] == 0){ //No sign necessary, convert as normal
//                 for(int i = 0; i < binary.size(); i++){
//                     result += binary[indices[i]] * pow(2,i);
//                 }
//             }
//             else{ //Negative, convert inverse and add 1, then make negative
//                 for(int i = 0; i < (indices.size()-1); i++){ //Size-1 to ignore sign bit
//                     result += ((binary[indices[i]] + 1) % 2) * pow(2,i); //Flip bits using %2
//                 }
//                 result += 1; //Add 1 (otherwise 1's complement)
//                 result *= -1; //Flip because negative!
//             }
//         }
//     }
//     return result;
// }

/* == strToVec ==
    Input:
        binary: string of binary digits. Assumes the lsb is the right-most character.
    
    Output:
        result: vector of integers converted from characters.
        
    Description:
        Takes in a string of binary digits, and populates an integer vector representing the binary code.*/
vector<int> strToVec(string binary){
    vector<int> result;
    for(int i = 0; i < binary.length(); i++){
        result.push_back((int)(binary[binary.length()-(i+1)])-48);
    }
    return result;
}

// Putting it all together!
int main(){
    vector<string> codes = {
        "01000000001000001000000110110011", //R-Type
        "00000000101001100111011010010011", //I-Type
        "11111110001100100000100000100011", //S-Type
        "11111110001000001001111011100011", //SB-Type
        "00000000101000000000000011101111"  //UJ-Type
    };

    vector<int> myVals;
    Field* myField;

    for(int i=0; i < codes.size(); i++){
        myVals = strToVec(codes[i]);
        cout << "- - -~~===oO00{O}0O0o===~~- - -" << endl;
        switch(i){
            case(0):
                myField = new RField(myVals);
                break;
            case(1):
                myField = new IField(myVals);
                break;
            case(2):
                myField = new SField(myVals);
                break;
            case(3):
                myField = new SBField(myVals);
                break;
            case(4):
                myField = new UJField(myVals);
                break;
        }   
        cout << codes[i] << endl;
        myField->printInfo();
        delete myField;
    }

}

//Testing binToInt, strToVec
// int main(){
//
//     string code;
//     cout << "Enter binary: ";
//     cin >> code;
//
//     vector<int> myVec = strToVec(code);
//
//     int result;
//     result = binToInt(myVec);
//     cout << result << endl;
//
//     return 0;
// }

//Testing RField
// int main(){
//     string myCode = "01000000001000001000000110110011";
//     vector<int> myVals = strToVec(myCode);
//     Field* myField = new RField(myVals);
//     myField->printInfo();
// }

//Testing IField
// int main(){
//     string myCode = "00000000101001100111011010010011";
//     vector<int> myVals = strToVec(myCode);
//     Field* myField = new IField(myVals);
//     myField->printInfo();
// }

// Testing SField
// int main(){
//     string myCode = "11111110001100100000100000100011";
//     vector<int> myVals = strToVec(myCode);
//     Field* myField = new SField(myVals);
//     myField->printInfo();
// }

// Testing binToInt Signed Conversion
// int main(){
//     vector<int> binary = {1,1,1,0,0,1,0,0,1,0,0,0};
//     cout << binToInt(binary, {}, true) << endl;
// }

// Testing SBField
// int main(){
//     string myCode = "11111110001000001001111011100011";
//     vector<int> myVals = strToVec(myCode);
//     Field* myField = new SBField(myVals);
//     myField->printInfo();
// }

// Testing UJField
// int main(){
//     string myCode = "00000000101000000000000011101111";
//     vector<int> myVals = strToVec(myCode);
//     Field* myField = new UJField(myVals);
//     myField->printInfo();
// }

