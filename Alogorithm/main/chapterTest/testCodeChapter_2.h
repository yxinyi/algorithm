#pragma once
#include <vector>
#include <algorithm>
#include "ApiAlgorithm.h"

void test_2_2_5(){
    std::vector<char > _vec = buildVec(39, 'Z', 'A');
    randomVecIdx(_vec);
    funcPrintVec(_vec);
    mergeSortDownUp<char>(_vec);
    funcPrintVec(_vec);
}
