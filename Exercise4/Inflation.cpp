#include <iostream>
#include <vector>
using namespace std;

int main() {
    double itemCost;
    int numOfYears;
    double inflation;
    cout << "Hello. Please enter the cost of the item: " << endl;
    cin >> itemCost;
    cout << "Please enter the number of years from now that the item will be purchased " << endl;
    cin >> numOfYears;
    cout << "Please enter the inflation rate as a percentage: " << endl;
    cin >> inflation;
    
    for (int i = 0; i < numOfYears; i ++) {
        itemCost += itemCost * (inflation/100);
    }
    
    cout << itemCost;
}