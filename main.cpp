// Winter'24
// Instructor: Diba Mirza
// Student name: 
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
        if (!line.empty()) {
            prefixes.push_back(line);
        }
    }


    //ryan - my current idea 
    //  for the prefixes, create a vector of vector<string>
    //  the vector<string> will store all titles that fit a prefix 
    //  the vector<vector<string>> stores ALL titles found
    //
    //  similar logic to a frequency table but instead of incrementing a value
    //  you push_back a movie title 
    //  alphabetical order should be dealt with by the original list

    //  For each prefix,
    //  Find all movies that have that prefix and store them in an appropriate data structure
    //  If no movie with that prefix exists print the following message
    //cout << "No movies found with prefix "<<"<replace with prefix>" << endl;

    //  For each prefix,
    //  Print the highest rated movie with that prefix if it exists.
    //cout << "Best movie with prefix " << "<replace with prefix>" << " is: " << "replace with movie name" << " with rating " << std::fixed << std::setprecision(1) << "replace with movie rating" << endl;

    //**** PART 2 */

    //Jesus-I'll be using your idea
    //However, I believe we'd run into errors if using vector<vector<string>> bc we'd lose rating information
    //Ill be using <vector<vector<Movie>> to keep both title and ratings

    //stores vectors of vectors for each prefix 
    vector<vector<Movie>> PrefixMatches; 

    //Fill in the table!
    //i for prefix
    for (int i = 0; i < prefixes.size(); i++) {
        vector<Movie> Match;  //inner vector kinda

        //j for eah movie
        for (int j = 0; j < movieVector.size(); j++) {
            //this will help us check if the movie starts with the prefix
            if (movieVector[j].getTitle().find(prefixes[i]) == 0) {
                //using .find strategy that we learned from cs16
                Match.push_back(movieVector[j]);  //pushed back into inner vector
            }

        }
        PrefixMatches.push_back(Match);  //final step
    }
    //attempt in handling the results per each prefix
    // *** I NEED HELP IN THIS ONE
    //idk if im doing it right ;)

    //ryan - commenting this code out for now

    //for (int i = 0; i < prefixes.size(); i++) {
    //    if (PrefixMatches[i].size() ==0) { //simple method to check if its empty
    //        cout << "No movies found with prefix "<< prefixes[i] << endl;
    //    }
    //    else {
            //here we sort them based on rating from highest to low
            //ties go to alphabetical order
            /*sort(PrefixMatches[i].begin(), PrefixMatches[i].end(), [] (const Movie& a, const Movie&b) { //using std::sort
                if (a.getRating() != b.getRating()) {//if the ratings are different (best case tbh)
                    return a.getRating() > b.getRating();

                }
                else { //if they are equal rating, sort by alphabetical order
                    return a.getTitle() < b.getTitle();

                }

            });
            //Now onto printing all matches
            //I think im doing something wrong here though, let me know
            //j for each movie
            for (int j = 0; j < PrefixMatches[i].size(); j++) {
                cout << PrefixMatches[i][j]; //this is the best method in using your << overloaded operands

            }
            //Project requirement; print out the best rated movie
            //in this case it should be the first element due to our sorting method
            cout << "Best movie with prefix " << prefixes[i] << " is: " << PrefixMatches[i][0].getTitle() << " with rating " << std::fixed << std::setprecision(1) << PrefixMatches[i][0].getRating() << endl;*/
            
    //   }
    //}
    
    //ryan - so the titles have to be in order by rating, highest to lowest 
    //       ill probably have to implement a new operator to do this :( 
    //       the double loop below prints out the titles with the requested formatting, but they are not in the correct order yet

    for (auto x : PrefixMatches){
        for (auto y : x){ //y refers to the vector<Movie> that stores movies of a certain prefix 
            if (y.size() > 0) cout << y;
        }
        cout << "\n";
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