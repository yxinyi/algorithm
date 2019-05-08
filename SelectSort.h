#pragma once
#include <vector>
#include <algorithm>

//从下标0开始开始遍历
void insertSort(std::vector<int>& vec) {
    for (int i = 1; i != vec.size(); i++) {
        for(int j = i ; j >0 && (vec[j] < vec[j - 1]);j--){
            std::swap(vec[j], vec[j-1]);
        }
    }
}


