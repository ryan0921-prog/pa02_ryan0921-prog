#include <vector> 
#include <queue> 
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