#pragma once
#include <vector>
#include <algorithm>

//从下标0开始开始遍历
void insertSort(std::vector<int>& vec) {
    for (int i = 1; i != vec.size(); i++) {
        for(int j = i ; j >0 ;j--){
            if(vec[j] < vec[j-1]){
                std::swap(vec[j], vec[j-1]);
            }
        }
    }
}


