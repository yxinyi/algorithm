#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
#include "Algorithm/ShellSort.h"
#include "Algorithm/SelectSort.h"
#include "Algorithm/InsertSort.h"
#include "Algorithm/MergeSort.h"
#include "Algorithm/QuickSort.h"
#include "Algorithm/MaxPq.h"

#define OPEN 1
#define CLOSE 0

#define printContorl OPEN

/*
ʱ�临�Ӷ�����Ϊʲô��NlogN
��һ������ΪN��������������������,����������Ϊȫ��Ԫ�������Ƚ�һ��,ÿ�β�ͬ�ıȽϿ��Կ�����ȫ������
����ӵ������(�����ʼΪ����)
�������߶�ΪlogN
�ӽڵ�������N!�ֿ���,��ΪN����������N!�ֿ��ܵıȽ�
����,ʱ�临�Ӷ�Ϊ N! << O << 2^h

���ݼ���,ʱ�临�Ӷ�ΪNlogN
*/


//�����������
template<class TBase>
void funcPrintVec(std::vector<TBase >& _vec) {
    if(printContorl == 0){
        return;
    }
    std::for_each(std::begin(_vec), std::end(_vec), [](const TBase i) {
        std::cout << i << std::ends;
    });
    std::cout << std::endl;
}

//��������
template<class TBase>
void randomVecIdx(std::vector<TBase >& _vec){
    srand((unsigned int)time(0));
    for(int i = 0 ; i != _vec.size(); i++){
        int _idx_0 = rand() % _vec.size();
        int _idx_1 = rand() % _vec.size();
        std::swap(_vec[_idx_0], _vec[_idx_1]);
    }
}


//��������
template<class TBase>
std::vector<TBase > buildVec(int size, TBase floor, TBase ceil) {
    srand((unsigned int)time(0));
    int _the_range = (ceil - floor);
    std::vector<TBase > _tmp_vec;
    for(int i = 0 ; i != size ;i ++){
        TBase _val = floor + (rand() % _the_range);
        _tmp_vec.push_back(_val);
    }
    return _tmp_vec;
}


//ѡ������
void selectSort(std::vector<int>& vec);
//��������
void insertSort(std::vector<int>& vec);
//ϣ������
void shellSort(std::vector<int>& vec);
//�鲢����
void mergeSort(std::vector<int>& vec);
//�鲢�������¶���
void mergeSortDownUp(std::vector<int>& vec);
//��������
template<class TBase>
void quickSort(std::vector<TBase>& vec);
//�����(���ȶ���)
template<class Type>
class SimpleMaxPq;
//������
template<class TBase>
void heapSort(std::vector<TBase>& vec);


