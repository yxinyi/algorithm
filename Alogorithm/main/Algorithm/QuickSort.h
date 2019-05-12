#pragma once
#include <vector>
#include "../ApiAlgorithm.h"
#include <algorithm>

/*
    如果左子数组和右子数组是有序的,
    那么由左子数组,切分元素和右紫数组组成的结果数组也一定是有序的
    快速排序
    找到一个切分元素,将切分元素两边的元素以切分元素为基准进行比较,使两侧都大于与小于切分元素
    然后再对剩余数组继续进行递归切分排序,直至无法继续切分
    确定切分元素之后,在起始处和末尾分别设置一个指针,分别向另一个方向移动,直至遇到适合的元素(左指针小于切分元素,右指针大于切分元素,进行交换)
    当指针相遇时,将切分元素与左指针指向的元素进行交换,就完成了快速排序
    时间复杂度 O(nlogn)
    */

template<class TBase>
int partition(std::vector<TBase>& vec, int left, int right){
    int _l_idx = left;
    int _r_idx = right + 1;
    TBase _the_key_val = vec[left];


    while(true){
        while (vec[++_l_idx] <_the_key_val)
        {
            if(_l_idx == right){
                break;
            }
        }
        while (_the_key_val < vec[--_r_idx])
        {
            if (left == _r_idx) {
                break;
            }
        }
        if(_l_idx >= _r_idx){
            break;
        }
        std::swap(vec[_l_idx], vec[_r_idx]);
    }
    std::swap(vec[left], vec[_r_idx]);
    return _r_idx;
}

template<class TBase>
void quickSort(std::vector<TBase>& vec, int left, int right) {
    if(left >= right){
        return;
    }
    int _cut_val = partition(vec, left,right);
    quickSort(vec, left, _cut_val-1);
    quickSort(vec, _cut_val+1,right );

}


template<class TBase>
void quickSort(std::vector<TBase>& vec) {
    quickSort(vec,0,vec.size()-1);
}


