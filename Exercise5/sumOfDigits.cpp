#include <iostream>
using namespace std;

int seperateDigits(int value) {
    int sum = 0;
    while (value != 0 ) {
        sum += value % 10;
        value /= 10; 
    }

    return sum;
}


int main() {
    int userNumber;
    int sum;
    while (cin >> userNumber) {
        cout << "Enter a number: " << endl;
        sum = seperateDigits(userNumber);
        cout << "The sum of your number is: " << sum << endl;
    }
    return 0;
}

    