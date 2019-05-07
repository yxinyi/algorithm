#include <iostream>
#include "ApiAlgorithm.h"
#include <algorithm>



int main(){
    std::vector<int > _vec = {1,3,6,9,7,1,0,3};
    selectSort(_vec);
    std::for_each(std::begin(_vec),std::end(_vec),[](const int i){
        std::cout << i << std::ends;
    });
    for(;;);;
    return 0;
}