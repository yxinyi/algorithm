#include <iostream>
#include "ApiAlgorithm.h"
#include "chapterTest/testCodeChapter_2.h"

void tmpTest(){
    std::vector<int > _vec = buildVec(5, 0, 100);
    randomVecIdx(_vec);
    funcPrintVec(_vec);
    quickSort(_vec);
    funcPrintVec(_vec);
}

int main(){
    tmpTest();
    for(;;);;
    return 0;
}