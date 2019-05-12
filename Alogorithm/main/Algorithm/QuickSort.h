#pragma once
#include <vector>
#include "../ApiAlgorithm.h"
#include <algorithm>

/*
    ���������������������������,
    ��ô����������,�з�Ԫ�غ�����������ɵĽ������Ҳһ���������
    ��������
    �ҵ�һ���з�Ԫ��,���з�Ԫ�����ߵ�Ԫ�����з�Ԫ��Ϊ��׼���бȽ�,ʹ���඼������С���з�Ԫ��
    Ȼ���ٶ�ʣ������������еݹ��з�����,ֱ���޷������з�
    ȷ���з�Ԫ��֮��,����ʼ����ĩβ�ֱ�����һ��ָ��,�ֱ�����һ�������ƶ�,ֱ�������ʺϵ�Ԫ��(��ָ��С���з�Ԫ��,��ָ������з�Ԫ��,���н���)
    ��ָ������ʱ,���з�Ԫ������ָ��ָ���Ԫ�ؽ��н���,������˿�������
    ʱ�临�Ӷ� O(nlogn)
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


