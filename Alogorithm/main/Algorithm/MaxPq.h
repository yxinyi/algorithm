#pragma once
#include <iostream>
#include "../ApiAlgorithm.h"

/*
    堆是一种数据结构,核心是一个完全二叉树
    二叉树的规则为,任意一个父节点都大于他的子节点
    优先队列可以基于有序数组或无序数组或堆来实现

    二叉树的左右子树不用比较大小,在下沉操作时会重新进行排序,虽然上浮期间没有比较两个子树

    插入元素LogN,取出元素LogN
*/

//基于堆的优先队列
template<class Type>
class SimpleMaxPq {
public:
    SimpleMaxPq():m_vec(1,0) {}
    ~SimpleMaxPq() {}
    //将第k个元素进行上浮
    void swim(int k){
        while(k > 1 && less(k/2,k)){
            std::swap(m_vec[k / 2], m_vec[k]);
            k = k/2;
        }
    }
    bool less(size_t lhs,size_t rhs){
        if(lhs >= m_vec.size() || rhs >= m_vec.size()){
            return false;
        }
        if((m_vec[lhs] < m_vec[rhs])){
            return true;
        }
        return false;
    }
    //将第k个元素下沉
    void sink(size_t k){
        while(2*k < m_vec.size()){
            //找到下一个子节点      1的子节点是2,3, 2的子节点是 4,5 
            size_t _idx = 2*k;
            //要比较的是两个子节点
            //vec[1] 要比较 vec[2]和vec[3],这里的做法是先比较2和3取最大者
            if(_idx < m_vec.size() && less(_idx, _idx + 1)){
                _idx++;
            }
            //当判断出来的节点大于指定节点时,进行交换,否则中断循环
            if(!(m_vec[k] < m_vec[_idx])){
                break;
            }
            std::swap(m_vec[k], m_vec[_idx]);
            //交换成功,将现在所处位置再次进行判断
            k = _idx;
        }
    }

    //向优先队列插入
    void insert(Type v){
        m_vec.push_back(v);
        //插入元素后,将最后一个元素进行上浮操作
        swim(m_vec.size()-1);
    }

    void size(){
        //为0的下标不使用
        return m_vec.size()-1;
    }

    Type delMax(){
        //先获取当前最大值
        Type _rst = m_vec[1];
        //将其与当前最小值进行交换
        std::swap(m_vec[1],m_vec[m_vec.size()-1]);
        //删除被拿出的最大值
        m_vec.erase(m_vec.end()-1);
        //然后将当前位置为1的值进行下潜
        sink(1);
        return _rst;
    }
    void print(){
        funcPrintVec(m_vec);
    }
private:
    std::vector<Type> m_vec;
};

template<class Type>
bool less(std::vector<Type>& m_vec,size_t lhs, size_t rhs) {
    if (lhs >= m_vec.size() || rhs >= m_vec.size()) {
        return false;
    }
    if ((m_vec[lhs] < m_vec[rhs])) {
        return true;
    }
    return false;
}

template<class Type>
void sink(std::vector<Type>& m_vec, size_t k, size_t n){
    while (2 * k < n) {
        //找到下一个子节点      1的子节点是2,3, 2的子节点是 4,5 
        size_t _idx = 2 * k;
        //要比较的是两个子节点
        //vec[1] 要比较 vec[2]和vec[3],这里的做法是先比较2和3取最大者
        if (_idx < n && less(m_vec, _idx, _idx + 1)) {
            _idx++;
        }
        //当判断出来的节点大于指定节点时,进行交换,否则中断循环
        if (!(m_vec[k] < m_vec[_idx])) {
            break;
        }
        std::swap(m_vec[k], m_vec[_idx]);
        //交换成功,将现在所处位置再次进行判断
        k = _idx;
    }
}

template<class TBase>
void heapSort(std::vector<TBase>& vec){
    int _len = vec.size()-1;
    funcPrintVec(vec);
    for(int i = _len /2 ; i >= 1 ; i--){
        sink(vec, i, _len);
    }
    funcPrintVec(vec);
    while (_len > 1)
    {
        std::swap(vec[1], vec[_len--]);
        sink(vec, 1, _len);
    }

}