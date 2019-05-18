#include <iostream>
#include <map>
#include "ApiAlgorithm.h"
#include "chapterTest/testCodeChapter_2.h"

void tmpTest(){
    BinarySortTree<int,int> _bst;
    _bst.put(10, 50);
    _bst.put(5, 50);
    _bst.put(123, 50);
    _bst.put(2, 50);
    _bst.put(23, 50);
    _bst.put(4, 50);
    _bst.put(11, 51);
    std::cout << _bst.max() << std::endl;
    _bst.deleteMax();
    std::cout << _bst.max() << std::endl;
    _bst.deleteMax();
    std::cout << _bst.max() << std::endl;
    _bst.deleteMax();
    std::cout << _bst.max() << std::endl;
    _bst.deleteMax();
    std::cout << _bst.max() << std::endl;
    _bst.deleteMax();
    std::cout << _bst.max() << std::endl;
    _bst.deleteMax();
    std::cout << _bst.max() << std::endl;
    _bst.deleteMax();
}

int main(){
    tmpTest();
    for(;;);;
    return 0;
}