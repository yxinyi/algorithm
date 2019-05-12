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
时间复杂度上限为什么是NlogN
当一个长度为N的数组进行最理想的排序,最基本的情况为全部元素两两比较一次,每次不同的比较可以看做完全二叉树
在最复杂的情况下(数组初始为倒序)
二叉树高度为logN
子节点最少有N!种可能,因为N个主键会有N!种可能的比较
所以,时间复杂度为 N! << O << 2^h

根据计算,时间复杂度为NlogN
*/


//数组输出函数
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

//打乱数组
template<class TBase>
void randomVecIdx(std::vector<TBase >& _vec){
    srand((unsigned int)time(0));
    for(int i = 0 ; i != _vec.size(); i++){
        int _idx_0 = rand() % _vec.size();
        int _idx_1 = rand() % _vec.size();
        std::swap(_vec[_idx_0], _vec[_idx_1]);
    }
}


//生成数组
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


//选择排序
void selectSort(std::vector<int>& vec);
//插入排序
void insertSort(std::vector<int>& vec);
//希尔排序
void shellSort(std::vector<int>& vec);
//归并排序
void mergeSort(std::vector<int>& vec);
//归并排序自下而上
void mergeSortDownUp(std::vector<int>& vec);
//快速排序
template<class TBase>
void quickSort(std::vector<TBase>& vec);
//二叉堆(优先队列)
template<class Type>
class SimpleMaxPq;
//堆排序
template<class TBase>
void heapSort(std::vector<TBase>& vec);


