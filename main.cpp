// Winter'24
// Instructor: Diba Mirza
// Student name: Ryan Sun and Jesus Santibanez
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include <sstream>
using namespace std;

#include "utilities.h"
#include "movies.h"

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
    if (argc < 2){
        cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
        cerr << "Usage: " << argv[ 0 ] << " moviesFilename prefixFilename " << endl;
        exit(1);
    }

    ifstream movieFile (argv[1]);
 
    if (movieFile.fail()){
        cerr << "Could not open file " << argv[1];
        exit(1);
    }
  
    // Create an object of a STL data-structure to store all the movies
    vector<Movie> movieVector; 

    string line, movieName;
    double movieRating;
    // Read each file and store the name and rating
    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
            // Use std::string movieName and double movieRating
            // to construct your Movie objects
            // cout << movieName << " has rating " << movieRating << endl;
            // insert elements into your data structure
            Movie newMovie(movieName, movieRating);
            movieVector.push_back(newMovie); 
    }

    movieFile.close();

    heapSort(movieVector); //sort vector 
    if (argc == 2){
        //print all the movies in ascending alphabetical order of movie names
        for (auto x : movieVector){
            cout << x;
        }
        return 0;
    }

    ifstream prefixFile (argv[2]);

    if (prefixFile.fail()) {
        cerr << "Could not open file " << argv[2];
        exit(1);
    }

    vector<string> prefixes;
    while (getline (prefixFile, line)) {
        if (!line.empty()){
            prefixes.push_back(line);
        }
    }

    vector<vector<Movie>> PrefixMatches; 

    //Fill in the table!
    //i for prefix
    /*for (int i = 0; i < prefixes.size(); i++) {
        vector<Movie> Match;  //inner vector kinda
        //auto start = lower_bound(movieVector.begin(), movieVector.end(), prefixes[i]);
        //j for eah movie
        for (int j = 0; j < movieVector.size(); j++) {
            //this will help us check if the movie starts with the prefix
            if (movieVector[j].getTitle().find(prefixes[i]) == 0) {
                //using .find strategy that we learned from cs16
                Match.push_back(movieVector[j]);  //pushed back into inner vector
            }

        }
        PrefixMatches.push_back(Match);  //final step
    }*/

    for (int i = 0; i < prefixes.size(); i++){
        vector<Movie> Match; 
        int start = binarySearch(movieVector, prefixes[i]);

        if (start != -1) {
            for (int j = start; j < movieVector.size(); j++) {
                if (movieVector[j].getTitle().substr(0, prefixes[i].size()) == prefixes[i]){
                    Match.push_back(movieVector[j]);
                }
                else if (movieVector[j].getTitle().substr(0, prefixes[i].size()) > prefixes[i]){
                    break;
                }   
            }
        }
        PrefixMatches.push_back(Match);
    }

    //sort prefixed movie titles by rating 
    for (auto& x : PrefixMatches){
        mergeSort(x); 
    }

    int i = 0; 
    //print prefixed titles 
    for (auto& x : PrefixMatches){ //x refers to vector<Movie> in PrefixMatches 
        if (x.size() == 0) cout << "No movies found with prefix " << prefixes[i]; 
        for (auto y : x){ //y refers to elements of vector<Movie> (the movies themselves)
            cout << y.getTitle() << ", " << fixed << setprecision(1) << y.getRating() << "\n";
        }
        cout << "\n";
        i++;
    }

    i = 0; 
    //print highest rated prefixed titles 
    for (auto& x : PrefixMatches){
        if (x.size() > 0){ 
            cout << "Best movie with prefix " << prefixes[i] << " is: " 
                 << x[0].getTitle() << " with rating " 
                 << fixed << setprecision(1) <<  x[0].getRating() << "\n"; 
        }
        i++; 
    }
}

/* Add your run time analysis for part 3 of the assignment here as commented block*/

bool parseLine(string &line, string &movieName, double &movieRating) {
    int commaIndex = line.find_last_of(",");
    movieName = line.substr(0, commaIndex);
    movieRating = stod(line.substr(commaIndex+1));
    if (movieName[0] == '\"') {
        movieName = movieName.substr(1, movieName.length() - 2);
    }
    return true;
}