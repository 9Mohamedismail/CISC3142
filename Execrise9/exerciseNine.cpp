#include <iostream>
#include <vector>  
#include <fstream>
#include <utility>
using namespace std;


// Parse the Text to seperate the MONTH & TEMPERATURE that is being read in from the CVS (seperated by commas).
void parseText(string readIn, vector<pair<string, int>>& vect, int index){
    string parsedMonth;
    string parsedTemp;
    bool monthComplete = false;

    for(auto c: readIn) {
        if (c != ',' && monthComplete == false) {
            parsedMonth += c;
        } else if (c != ',' && monthComplete == true) {
           parsedTemp += c;
        } else {
            monthComplete = true;
            continue;
        }
    }
    vect[index].first = parsedMonth;
    vect[index].second = stoi(parsedTemp);
}

// Calculate the average of all 9 months in order to figure out what October would be.
// Send the 2D Vector & file to write to.
void isAverage(vector<pair<string, int>>& vect, ofstream& file){
    double average = 0;
    for(int i = 0; i < 10; i++) {
        average += vect[i].second;
    }

    file << "Using the simple average across all months in the data (9 months)." << endl;
    file << "We can predict that the weather for October would be: " <<  average/9 << "\n" << endl;
}

// Calculate the moving average of 3 months in order to figure out what October would be.
// Send the 2D Vector & file to write to.
void movingAverage(vector<pair<string, int>>& vect, ofstream& file){
    double average = 0;
    file << "Using July(85), August(81), and September(76) for the moving average formula." << endl;

    for(int i = 6; i < 10; i++) {
        average += vect[i].second;
    }

    file << "We can predict that the weather for October would be: " << average/3 << "\n" << endl;
}

// Calculate the weighted moving average of 3 months in order to figure out what October would be.
// Send the 2D Vector & file to write to.
void weightageMovingAverage(vector<pair<string, int>>& vect, ofstream& file){ 
    double average = 0;
    int weight = 0;
    file << "Using July(85), August(81), and September(76) for the weighted moving average formula." << endl;

    for(int i = 6; i < 10; i++) {
        weight++;
        average += vect[i].second * weight;
    }

    file << "We can predict that the weather for October would be: " << average/6;
}

int main() {
    ifstream weather("weather.csv.txt", ifstream::in); // Create a ifstream to read in the file "weather.csv".
    weather.ignore(10000,'\n'); // Ignores the first line, which is the header (Month,Temp).
    ofstream file ("output.txt"); // Creates an ofstream to write the output to a file.
    string textReadIn;
    int index = 0;

    vector<pair<string, int>> monthTemp(10);

    // A while loop to get each line in the .txt file. Send the entire line to parseText() to put values into the 2D Vector.
    while (getline(weather, textReadIn)) {
        parseText(textReadIn, monthTemp, index);
        index++;
    }
    weather.close(); // We no longer need to read from file, we can close it.
    
    // Calculate by sending 2D Vector into functions and the file we want to write to.
    isAverage(monthTemp, file);
    movingAverage(monthTemp, file);
    weightageMovingAverage(monthTemp, file);
    file.close(); // We no longer need to write to file, we can close it.


    return 0;
}