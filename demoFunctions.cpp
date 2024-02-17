#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

/* == binToInt ==
    Input:
        binary: list of binary digits to convert to decimal. Assumes lsb is stored at index 0.
        (optional) indices: if provided, takes binary digits at the provided indices, starting from the index at indices[0].
        
    Output:
        result: integer conversion of the binary digits to decimal. 
        
    Description:
        Takes in binary digits and optional indices to choose from, and returns the value converted to binary in an integer. */
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


int main(){
    
    string code;
    cout << "Enter binary: ";
    cin >> code;

    vector<int> myVec = strToVec(code);

    int result;
    result = binToInt(myVec);
    cout << result << endl;

    return 0;
}