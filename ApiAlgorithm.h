#pragma once
#include <vector>
#include <algorithm>
#include "ShellSort.h"
#include "SelectSort.h"
#include "InsertSort.h"
#include "MergeSort.h"


//ѡ������
void selectSort(std::vector<int>& vec);
//��������
void insertSort(std::vector<int>& vec);
//ϣ������
void shellSort(std::vector<int>& vec);
//�鲢����
void mergeSort(std::vector<int>& vec);