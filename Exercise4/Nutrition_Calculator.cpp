#include <iostream>

using namespace std;

int main()
{
    double sweetenerToKillAMouse;
    double weightOfMouse;
    double weightOfDieter;
    double resultSoda;
    const double sweetenerInSoda = 0.001;
    char replayResult;

    // I don't see why we need to know the mass of the soda
    // Therefore, I didn't use the following inforomation:
    // "A single can of soda pop has a mass of 350 grams"
    
    cout << "How much sweetner is needed to kill a mouse?" << endl;
    cin >> sweetenerToKillAMouse;
    cout << "What is the weight of the mouse?" << endl;
    cin >> weightOfMouse;
    cout << "What is the weight at which the dieter will stop dieting" << endl;
    cin >> weightOfDieter;

    resultSoda = (sweetenerToKillAMouse / weightOfMouse) * weightOfDieter / sweetenerInSoda;
    
    cout << "It is possible to drink " << resultSoda << " diet soda pop without dying as a result" << endl;

    cout << "Would you like to recalcuate? Type 'Y' for yes and 'N' for no (Anything else will close the program)" << endl;
    cin >> replayResult;

    if (replayResult == 'Y') {
        main();
    }  else if (replayResult == 'N') { 
        exit(0);
    }
}