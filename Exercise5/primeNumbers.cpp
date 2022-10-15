#include <iostream>
using namespace std; 

bool isThisNumberPrime(int x) {

    for (int i = 2; i <= x/2; i++ ){
        if ((x % i) == 0) {
            return false;
            break;
        }
    }
    return true;
}

int main() {
    for (int i = 3; i < 100; i++) {
        if (isThisNumberPrime(i)) {
            cout << i << endl;
        }
    }
}
