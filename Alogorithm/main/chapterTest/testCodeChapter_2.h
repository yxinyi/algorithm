#pragma once
#include <vector>
#include <algorithm>
#include "ApiAlgorithm.h"

void test_2_2_5(){
    std::vector<char > _vec = buildVec(39, 'Z', 'A');
    randomVecIdx(_vec);
    funcPrintVec(_vec);
    //mergeSortDownUp<char>(_vec);
    mergeSort<char>(_vec);
    funcPrintVec(_vec);
}

void test_2_2_6() {
    for(int _sz = 1 ; _sz != 512 ;_sz++){
        std::vector<char > _vec = buildVec(_sz, 'Z', 'A');
        randomVecIdx(_vec);
        funcPrintVec(_vec);
        mergeSort<char>(_vec);
        funcPrintVec(_vec);
    }
}
