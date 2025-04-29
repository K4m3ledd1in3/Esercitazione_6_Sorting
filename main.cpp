#include <cmath> 
#include <iostream>
#include <numeric> 
#include <iostream>
#include <sstream>
#include <chrono> 
#include <iomanip>
#include <random>
#include "SortingAlgorithm.hpp"
using namespace std;

//Consideration:
//Bubble Sort is efficient for small-size vector, instead Heap Sort is handy for large-size vector.

/*
The test was undertook with 2 types of vectors, one which elements are pseudo-random, the second one
is as the first half is made up by random elements which seeds is changing every cycle depending on index 
of iteration, the second half is the same as the fist one.
*/
vector<double> RanDouble(size_t size){
	std::vector<double> v(size);
    std::random_device rd;
    std::mt19937 gen(rd());     // Mersenne Twister RNG
    std::uniform_real_distribution<> dis(0.0, 100.0);

    for (auto& x : v) {
        x = dis(gen);
    }
	return v;
}
vector<int> RanInt(size_t size){
	std::vector<int> v(size);
    std::random_device rd;
    std::mt19937 gen(rd());  
    std::uniform_real_distribution<> dis(0.0, 100.0);

    for (auto& x : v) {
        x = dis(gen);
    }
	return v;
}
int main(void)
{       		   
	size_t size;
	cout << "Insert the vector'size:";
	cin >> size;
    unsigned int num_experiment = 10;
    double time_elapsed_heap_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
    	vector<double>v2 = RanDouble(size);
        vector<double> v(v2);
        SortLibrary::Implicit_Heap<double> a(v);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        a.HeapSort();
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v1 /= num_experiment;

    
    double time_elapsed_heap_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
		vector<int>v2 = RanInt(size);
   		vector<int> v3(size, 0);
   		srand(t);
        for(size_t i = floor(size * 0.5) + 1; i < size; i++)
        	v3[i] = (rand() % (1000));
        copy(v2.begin(), v2.begin() + floor(size * 0.5) + 1, v3.begin());
        vector<int> v(v3);
        SortLibrary::Implicit_Heap<int> a(v);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        a.HeapSort();
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v2 /= num_experiment;

    
    num_experiment=1000;

    double time_elapsed_bubble_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
    	vector<double>v2 = RanDouble(size);
        vector<double> v(v2);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v1/= num_experiment;
    
    
    double time_elapsed_bubble_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {	
        vector<int> v2 =  RanInt(size);
   		vector<int> v3(size);
   		srand(t);
        for(size_t i = floor(size * 0.5) + 1; i < size; i++)
        	v3[i] = (rand() % (1000));
        copy(v2.begin(), v2.begin() + floor(size * 0.5) + 1, v3.begin());
        vector<int> v(v3);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v2 /= num_experiment;
    std::cout <<"Runtime sorting algorithms:"<< std::endl;
    std::cout << "Heap Sort - v1: " << time_elapsed_heap_v1 << std::endl;
    std::cout << "Heap Sort - v2: " << time_elapsed_heap_v2 << std::endl;
	std::cout << "Bubble Sort - v1: " << time_elapsed_bubble_v1 << std::endl;
	std::cout << "Bubble Sort - v2: " << time_elapsed_bubble_v2 << std::endl;
    return 0;
}

