
#ifndef MOVIES_H
#define MOVIES_H
#include <ostream>

class Movie{
    public: 
        Movie(); 
        Movie(std::string t, double r); 

        void setTitle(std::string t); 
        void setRating(double r); 

        std::string getTitle() const; 
        double getRating() const; 

        //ryan - im thinking of using a minheap sort so we'll just need a less-than operator 
        bool operator>(const Movie& other) const; 
        
    private: 
        std::string title; 
        double rating; 
};

std::ostream& operator<<(std::ostream&os, const Movie& movie); 

#endif