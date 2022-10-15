#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


double sumOfValues(vector<double> values) {
    double valueSum = 0;
    for (int i = 0; i < values.size(); i++) {
        valueSum += values.at(i);
    }
        return valueSum;

}

double findBOneNum(vector<double> xValue, vector<double> yValue, double sumOfXValues, double sumOfYValues) {
    double bOneSum = 0;
    double bOneSumTwo = 0;
    double bOneResult = 0;
    for (int i = 0; i < xValue.size(); i++) {
        bOneSum = xValue.at(i) - sumOfXValues;
        bOneSumTwo = yValue.at(i) - sumOfYValues;
        bOneResult += bOneSum * bOneSumTwo;
    }
        return bOneResult;
}

double findBOneDen(vector<double> xValues, double sumOfXValuesDen) {
    double bOneXResult;
    for (int i = 0; i < xValues.size(); i++) {
        double bOneXSum = 0;
        bOneXSum += xValues.at(i) - sumOfXValuesDen;
        bOneXResult += pow(bOneXSum, 2);
    }   
        return bOneXResult;
}

int main() {
    vector<double> yValues;
    vector<double> xValues;
    double numberRead, numberReadTwo;
    double sumOfYValues, sumOfXValues;
    double bOneXValues, bOneYValues;
    double bOneFormula, bOneFormulaNum, bOneFormulaDen;
    double bZeroFormula, bZeroFormulaTwo;

    while(cin >> numberRead >> numberReadTwo ) {
        yValues.insert(yValues.end(), numberRead);
        xValues.insert(xValues.end(), numberReadTwo);    
    }

    sumOfYValues = sumOfValues(yValues) / yValues.size();
    sumOfXValues = sumOfValues (xValues) / xValues.size();

    cout << "mean of X values: " << sumOfXValues << endl;
    cout << "mean of Y values: " << sumOfYValues << endl;

    bOneFormulaNum = findBOneNum(xValues, yValues, sumOfXValues, sumOfYValues);
    bOneFormulaDen = findBOneDen(xValues, sumOfXValues);
    bOneFormula = bOneFormulaNum / bOneFormulaDen;

    cout << "Slope (b1): " << bOneFormula << endl;
   
    bZeroFormulaTwo = bOneFormula * sumOfXValues;  
    bZeroFormula = sumOfYValues - bZeroFormulaTwo;

    cout << "Intercept (b0): " << bZeroFormula << endl;
    cout << "Simple Linear Regression Model: " << bZeroFormula << " + " << bOneFormula << "x" << endl;

}
    