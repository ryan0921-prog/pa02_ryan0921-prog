class Movie{
    //not sure what data structure to use rn, just setting up some basics
    public: 
        Movie(); 
        Movie(string title, int rating); 

        void setTitle(string t); 
        void setRating(int r); 

        string getTitle(); 
        int getRating(); 

        
    private: 
        string title; 
        int rating; 
};