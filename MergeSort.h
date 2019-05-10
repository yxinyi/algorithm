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


void mergeSort(std::vector<int>& vec){

}