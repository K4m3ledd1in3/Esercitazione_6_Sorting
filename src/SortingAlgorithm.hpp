#pragma once

#include <iostream>
#include <vector>
#include <concepts>
using namespace std;
namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void Print(std::vector<T>& v){
	for(auto&c : v)
		std::cout << c <<" ";
	std::cout << std::endl;
}
template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
bool swap = true;
size_t n = v.size();
while(swap)
{
	swap = false;
	for(size_t i=0; i<n-1; i++)
	{
		if(v[i]>v[i+1]){
			T tmp = v[i+1];
			v[i+1] = v[i];
			v[i] = tmp;
			swap = true;
		}
	}		
}
//Print(v);
}
template<Sortable T>
class Implicit_Heap{
	std::vector<T> elements;
	uint heap_size;
	public:
		Implicit_Heap(std::vector<T> v) {
			heap_size = 0;
			for(auto& c: v){
				ENQUEUE(c);
			}
		   
		    cout << "ELEMENTS BEFORE HEAP SORT RSORTING:" << endl;
			for(auto&c:elements){
				cout << c << " ";
			}
			cout << endl;
		
		}
		Implicit_Heap()=delete;
		~Implicit_Heap()=default;
		void HeapSort(){
		std::vector<T> temp = elements; 
		uint temp_size = heap_size;
		std::vector<T> sorted(temp_size);
		for (size_t i = 0; i < sorted.size(); i++) {
			sorted[sorted.size() - 1 - i] = DEQUEUE();
		}
		string message = ">ELEMENTS AFTER HEAP SORT  SORTING: ";
		Print(sorted,message);
		elements = sorted;
		heap_size = temp_size;
		}
		
		vector<T> getElements(){
			return elements;
		}
		
		void ENQUEUE(T e){
			heap_size++;
    	    elements.push_back(e);  
    		Heap_Up(heap_size - 1);
		}
		T DEQUEUE(){
			if(!Empty() && heap_size>0 && elements.size()>0){
			T max = elements[0];
			elements[0]=elements[heap_size-1];
			elements.resize(heap_size - 1);
			heap_size--;
			Heap_Down(0);
			return max;
			}
			throw runtime_error("Dequeue from empty heap");
		}
		void Heap_Up(uint i){
			while(i>0 && elements[i]>elements[Father(i)]){
				Swap(i,Father(i));
				i=Father(i);
			}
		}
		void Heap_Down(uint i){
			while (true) {
   			 uint b = Best(i);
    		if (b == i) break;
    		Swap(i, b);
    		i = b;
			}
		}
		uint Best(uint i){
			uint l = Left(i);
			uint r = Left(i)+1;
			uint best = i;
			if (l < heap_size && l < elements.size() && elements[l] > elements[best]) {
    		best = l;
			}
			if (r < heap_size && r < elements.size() && elements[r] > elements[best]) {
    		best = r;
			}
			return best;
		}
		void Swap(uint i, uint j){
			T tmp = elements[i];
			elements[i] = elements[j];
			elements[j] = tmp;
		}
		uint Father(uint i){
			return (i-1)/2;
		}
		uint Left(uint i){
			return 2*i+1;
		}
		bool Empty(){
			return (heap_size==0);
		}
		void Print(const std::vector<T>& v, string& message) {
			std::cout << message << std::endl;
			for (const auto& el : v) {
			std::cout << el << " ";
			}
			std::cout << std::endl;
}
};
}

