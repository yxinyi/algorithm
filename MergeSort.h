#pragma once
#include <vector>
#include <algorithm>
#include "ApiAlgorithm.h"


/*
    归并排序是基于分治的思想,两个有序的数组进行合并的效率为On
    所以将所需要排序的数据不断的进行拆分,拆分成单位数量为1的数组,就可以视为该数组为有序的,然后逐级进行合并,最终完成排序
    用树形结构进行分析,该排序的效率是排序算法的上限,
    为Nlg(N)
*/

void merge(std::vector<int>& vec, int left, int mid,int right){
    std::cout << "merge( left:" << left << " mid: " << mid <<" right:" << right << ")"<<std::endl;
    int _len = right - left;
    std::vector<int> _rst_vec = vec;

    for(int _idx = left,_l = left, _r = mid+1; _idx <= right; _idx++){
        if(_l > mid){
            _rst_vec[_idx] = vec[_r++];
        }else if(_r > right){
            _rst_vec[_idx] = vec[_l++];
        }else if(vec[_l] >= vec[_r]){
            _rst_vec[_idx] = vec[_l++];
        }else if(vec[_r] > vec[_l]){
            _rst_vec[_idx] = vec[_r++];
        }
    }
    vec = _rst_vec;
}

void recursion(std::vector<int>& vec, int _l, int _r){
    if (_r <= _l) {
        return;
    }
    int _len = _r -_l;
    int _mid_idx = _l + _len /2;


    recursion(vec, _l, _mid_idx);
    recursion(vec, _mid_idx+1, _r);
    merge(vec,_l,_mid_idx,_r);
}

void mergeSort(std::vector<int>& vec){
    recursion(vec,0,vec.size()-1);
}