//minheap 
#include "movies.h"
void heapSort(std::vector<Movie>& vector);
void mergeSort(std::vector<Movie>& vector); 
void mergeHelper(std::vector<int>& result, std::vector<int>& left, std::vector<int>& right);
int binarySearch(std::vector<Movie>& vector, std::string& prefix); 