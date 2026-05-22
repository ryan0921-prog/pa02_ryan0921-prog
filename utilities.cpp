#include <vector> 
#include <queue> 
#include <iostream> 
#include <string> 
#include "movies.h"
#include "utilities.h"

//this is using a minheap 
//same logic from lecture but resorting the vector from beginning to end 
void heapSort(std::vector<Movie>& vector){
    std::priority_queue<Movie, std::vector<Movie>, std::greater<Movie>> minheap;

    //heapify 
    for (auto x : vector){
        minheap.push(x); 
    }

    //sort 
    int i = 0;
    while (minheap.size() > 0){
        vector[i] = minheap.top(); 
        minheap.pop(); 
        i++;
    }
}

//copy and pasted from lecture :)))))
//modified to suit our needs 
void mergeHelper(std::vector<Movie>& result, std::vector<Movie>& left, std::vector<Movie>& right){
    int i = 0; 
    int j = 0; 
    int k = 0; //index of element to place into the result vector 

    while(i < left.size() && j < right.size()){
        //std::cout << "hi\n";
        if(left[i].getRating() >= right[j].getRating()){
            result[k] = left[i];
            i++; 
            k++; 
        }
        else{
            result[k] = right[j]; 
            j++;
            k++; 
        }
    }
    while(i < left.size()){
        result[k] = left[i]; 
        i++;
        k++; 
    }
    while(j < right.size()){
        result[k] = right[j]; 
        j++;
        k++; 
    }
}

void mergeSort(std::vector<Movie>& vector){
    if (vector.size() <= 1) return; 
    int mid = vector.size() / 2; 
    std::vector<Movie> left(vector.begin(), vector.begin() + mid); 
    std::vector<Movie> right(vector.begin() + mid, vector.end()); 
    mergeSort(left);
    mergeSort(right); 
    mergeHelper(vector,left,right); 
}

//finding first prefix
int binarySearch(std::vector<Movie>& vector, std::string& prefix){
    int low = 0; 
    int high = vector.size() - 1; 
    int start = -1; 

    while (low <= high){
        int mid = (low + high) / 2; 
        if (vector[mid].getTitle().substr(0, prefix.size()) >= prefix) {
            start = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return start; 
} 