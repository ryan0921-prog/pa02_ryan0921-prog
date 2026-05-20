#include <string> 
#include "movies.h"


//Default constructor
Movie::Movie() {
    rating = 0;  //setting our rating to be zero
    title = "";  //seting our title to be empty
}

//Customed constructor
Movie::Movie(std::string t, double r) {
    title = t; //established the tittle
    rating = r; //establishes the rating
}


//setter for titles
void Movie::setTitle(std::string t) {
    title = t;  //set title to whatever is inputed
}

//setter for ratings
void Movie::setRating(double r) {
    rating = r;  //set rating to whatver is inputed
}
//getter for titles
std::string Movie::getTitle() const{
    return title;  //returns our title
}
//getters for rarting
double Movie::getRating() const{
    return rating; //returns our rating
}

bool Movie::operator>(const Movie& other) const{
    if (title.compare(other.title) > 0) return true; 
    return false; 
}

//probably won't need this :)
std::ostream& operator<<(std::ostream& os, const Movie& movie){
    os << movie.getTitle() << ", " << movie.getRating() << "\n"; 
    return os; 
}