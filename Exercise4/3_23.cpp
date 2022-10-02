#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> doubleVector(10);

    doubleVector[0] = 1;

    for (int i = 1; i < 10; i++) {
       doubleVector[i] = doubleVector[i-1] * 2;
       cout << doubleVector[i-1] << ", ";
    }

    cout << doubleVector.back();
    
}