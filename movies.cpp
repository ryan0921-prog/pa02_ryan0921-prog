#include "movies.h"


//Default constructor
Movie::Movie() {
    rating = 0;  //setting our rating to be zero
    title = "";  //seting our title to be empty
}

//Customed constructor
Movie::Movie(string title, int rating) {
    this->title = title; //established the tittle
    this->rating = rating; //establishes the rating

}


//setter for titles
void Movie::setTitle(string t) {
    title = t;  //set title to whatever is inputed
}

//setter for ratings
void Movie::setRating(int r) {
    rating = r;  //set rating to whatver is inputed
}
//getter for titles
string Movie::getTitle() {
    return title;  //returns our title
}
//getters for rarting
int Movie::getRating() {
    return rating; //returns our rating
}