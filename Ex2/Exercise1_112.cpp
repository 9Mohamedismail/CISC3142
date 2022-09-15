#include <iostream>
using namespace std;

int main() {
    int numOne;
    int numTwo;

    cout << "Input the first number:";
        cin >> numOne;
    cout << "Input the second number:";
        cin >> numTwo;
    cout << numOne;

    while(numTwo > numOne){
        numOne++;
        cout << numOne;
    }
}