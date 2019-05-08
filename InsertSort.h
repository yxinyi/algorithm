#pragma once
#include <vector>
#include <algorithm>

//每次将最小的数放到最前面
//效率: (N^2)/2
void selectSort(std::vector<int>& vec) {
    for (int i = 0; i != vec.size(); i++) {
        int _mix_idx = i;
        for (int j = i + 1; j != vec.size(); j++) {
            if (vec[j] < vec[_mix_idx]) {
                _mix_idx = j;
            }
        }
        std::swap(vec[_mix_idx], vec[i]);
    }
}


