#include <iostream>
#include "ApiAlgorithm.h"



int main(){
    std::vector<int > _vec = {6,5,4,3,1,7,2};
    mergeSort(_vec);
    std::for_each(std::begin(_vec),std::end(_vec),[](const int i){
        std::cout << i << std::ends;
    });
    for(;;);;
    return 0;
}