#include <iostream>
#include <vector>
using namespace std;

void convertToUpperCase(string& inputString){
        for (int i=0; i < inputString.length(); i++){
            inputString[i] = toupper(inputString[i]);
        }
    }

int main() {
    string input;
    vector<string> words(8);

    cout << "Type 8 seperate words: ";
    for (int i = 0; i < 8; i++) {
       cin >> input;
       convertToUpperCase(input);
       words[i] = input;
    }

    for (int j = 0; j < 8; j++) {
       cout << words[j] << ", ";
    }


}