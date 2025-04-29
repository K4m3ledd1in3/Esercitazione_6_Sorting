#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <gtest/gtest.h>
#include <random>
#include "SortingAlgorithm.hpp"

namespace SortLibrary {
std::vector<double> RanDouble(size_t size){
	std::vector<double> v(size);
    std::random_device rd;
    std::mt19937 gen(rd());     // Mersenne Twister RNG
    std::uniform_real_distribution<> dis(0.0, 100.0);

    for (auto& x : v) {
        x = dis(gen);
    }
	return v;
}
std::vector<int> RanInt(size_t size){
	std::vector<int> v(size);
    std::random_device rd;
    std::mt19937 gen(rd());  
    std::uniform_real_distribution<> dis(0.0, 100.0);

    for (auto& x : v) {
        x = dis(gen);
    }
	return v;
}
const size_t size = 10;
TEST(TestSorting, TestBubbleSort)
{
	
    std::vector<double> v = RanDouble(size);
    std::vector<double> z(v);
    std::sort(z.begin(),z.end());
    BubbleSort<double>(v);
    EXPECT_EQ(z, v);
}

TEST(TestSorting, TestHeapSort)
{
    std::vector<double> v = RanDouble(size);
    std::vector<double> z(v);
    SortLibrary::Implicit_Heap<double> a(v); 
	a.HeapSort();   
    std::sort(z.begin(),z.end());
    EXPECT_EQ(a.getElements(), z);
}

}
