#pragma once
#include <vector>
#include "ApiAlgorithm.h"
#include <algorithm>

//ÿ�ν���С�����ŵ���ǰ��
//���Ч��: (N^2)/2
void shellSort(std::vector<int>& vec) {
    int n = vec.size();
    int h = 1;
    while(h< n/3){ h = 3 *h +1;}
    while(h >= 1){
        for (int i = h; i != vec.size(); i++) {
            for (int j = i; j >= h && (vec[j] < vec[j - h]); j -= h) {
                std::swap(vec[j], vec[j - h]);
            }
        }
        h = h/3;
    }
}


