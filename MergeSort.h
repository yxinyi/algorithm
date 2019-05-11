#pragma once
#include <vector>
#include <algorithm>
#include "ApiAlgorithm.h"


/*
    �鲢�����ǻ��ڷ��ε�˼��,���������������кϲ���Ч��ΪOn
    ���Խ�����Ҫ��������ݲ��ϵĽ��в��,��ֳɵ�λ����Ϊ1������,�Ϳ�����Ϊ������Ϊ�����,Ȼ���𼶽��кϲ�,�����������
    �����νṹ���з���,�������Ч���������㷨������,
    ΪNlg(N)
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