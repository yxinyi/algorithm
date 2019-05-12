#include <iostream>
#include "ApiAlgorithm.h"
#include "chapterTest/testCodeChapter_2.h"

void tmpTest(){
    //std::vector<int> _vec = buildVec(10, 0, 60);
    std::vector<int> _vec = {1,2,3,4,5,6,7,8,9};
    randomVecIdx(_vec);
    _vec.insert(_vec.begin(),0);
    heapSort(_vec);
    funcPrintVec(_vec);
}

int main(){
    tmpTest();
    for(;;);;
    return 0;
}