#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <numeric>
#include <algorithm>
using namespace std;

struct filmFile {
       int year, length, popularity;
       string title, subject, actor, actress, director, awards, image;
       string tempstring = "";
};

void createVector(vector<filmFile>& vect, int year, int length, int popularity, string title, 
                string subject, string actor, string actress, string director, string awards, string image, int i)
    {
            vect.at(i).year = year;
            vect.at(i).length = length;
            vect.at(i).title = title;
            vect.at(i).subject = subject;
            vect.at(i).actor = actor;
            vect.at(i).actress = actress;
            vect.at(i).director = director;
            vect.at(i).popularity = popularity;
            vect.at(i).awards = awards;
            vect.at(i).image = image;               
}

void extractUniqueEqual(vector<filmFile>& vect, ofstream& file) {
    vector<filmFile> actionMovies;
    vector<filmFile> comedyMovies;

    // Extract Vectors into 'ACTION' and 'COMEDY'
    int index;
    for (index = 0; index < vect.size(); index++) {
        if (vect.at(index).subject == "Action") {
            actionMovies.push_back (vect.at(index));
        } else if (vect.at(index).subject == "Comedy") {
            comedyMovies.push_back (vect.at(index));
        }
    }

    // Check for UNIQUE values in 'ACTION' vector
    auto it = unique(actionMovies.begin(), actionMovies.end(), [] (filmFile const & l, filmFile const & r) {return l.year == r.year; } );
    actionMovies.erase(it, actionMovies.end());
    file << "\n(UNIQUE) The unique years for ACTION movies are: ";
    for (index = 0; index < actionMovies.size(); index++) {
        file << actionMovies.at(index).year << ", ";
    }

    // Check for UNIQUE values in 'COMEDY' vector
    auto itTwo = unique(comedyMovies.begin(), comedyMovies.end(), [] (filmFile const & l, filmFile const & r) {return l.year == r.year; } );
    comedyMovies.erase(itTwo, comedyMovies.end());
    file << "\n\n(UNIQUE) The unique years for COMEDY movies are: "; 
    for (index = 0; index < comedyMovies.size(); index++) {
        file << comedyMovies.at(index).year << ", ";
    }

    // Since the equal() method doesn't really work here, I used a simply if loop to do the same thing.
    bool isEqual;
    for (index = 0; index < actionMovies.size(); index++){
        if (actionMovies.at(0).year == comedyMovies.at(0).year) {
            isEqual = true;
        } else {
            isEqual = false;
            goto end;
        }
    }
    end: string output = isEqual ? "true" : "false";
    file << "\n\n(EQUAL) Are both unique lists equal to each other: " << output << endl;
}   

// Used for the sort() method
bool compareByLength(const filmFile &x, const filmFile &y)
{
    return x.popularity > y.popularity; 
}

int main() {
    ifstream film("film.csv.txt", ifstream::in);
    ofstream file ("output.txt"); 
    string line = "";
    int index = 0;

    vector<filmFile> films(50);
    vector<filmFile>::iterator it;

    // Reads in the entire file (it's a lot)
    while(getline(film,line)){
        int year, length, popularity;
        string title, subject, actor, actress, director, awards, image;
        string tempstring = "";
        
        stringstream inputString(line);
        getline(inputString, tempstring, ';');
        year = atoi(tempstring.c_str());
        tempstring = "";
        getline(inputString, tempstring, ';');
        length = atoi(tempstring.c_str());
        getline(inputString, title, ';');
        getline(inputString, subject, ';');
        getline(inputString, actor, ';');
        getline(inputString, actress, ';');
        getline(inputString, director, ';');
        tempstring = "";
        getline(inputString, tempstring, ';');
        popularity = atoi(tempstring.c_str());
        getline(inputString, awards, ';');
        getline(inputString, image, ';');

        createVector(films, year, length, popularity, title, subject, actor, actress, director, awards, image, index);
        index++;
    }
    film.close();

    // The accumulate() method
    int sum = accumulate (films.begin(), films.end(), 0, 
    [](int i, const filmFile& o){ return o.popularity + i; } );

    file << "\n(ACCUMULATE) The total sum length of all movies is: " << sum << endl;

    // The sort() method
    sort(films.begin(), films.end(), compareByLength);
    file << "\n(SORT) Movies in descending order by popularity: " << endl;
    
    for (int k = 0; k < films.size(); k++) {
        file << films.at(k).title << " (" << films.at(k).popularity << "), ";
    }

    // The find() method
    it = find_if(films.begin(), films.end(),  [](filmFile& f){ return f.title == "Days of Heaven"; } );
    if (it != films.end())
    {
        file << "\n\n(FIND) Element 'Days of Heaven' found at position : ";
        file << it - films.begin() << " (counting from zero) \n" ;
    }

    // Calls the function to extract the vectors, find the unique values, and compare them
    extractUniqueEqual(films, file);
    file.close();
}