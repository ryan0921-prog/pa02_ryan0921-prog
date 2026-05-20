#include <vector> 
#include <queue> 
#include "movies.h"
#include "utilities.h"

void heapSort(std::vector<Movie>& vector){
    std::priority_queue<Movie, std::vector<Movie>, std::greater<Movie>> minheap; 
    for (auto x : vector){
        minheap.push(x); 
    }
    int i = 0;
    while (minheap.size() > 0){
        vector[i] = minheap.top(); 
        minheap.pop(); 
        i++;
    }
}