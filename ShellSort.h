#pragma once
#include <vector>
#include "ApiAlgorithm.h"
#include <algorithm>

/*
    希尔排序 > 插入排序
    希尔排序是基于插入排序的
    设置一个增量,将数据分成多个组,分别对各组进行排序
    排序完成后,逐渐减少增量,并重复排序过程,直至增量为1
*/

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


