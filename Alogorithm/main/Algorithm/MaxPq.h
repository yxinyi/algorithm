#pragma once
#include <iostream>
#include "../ApiAlgorithm.h"

/*
    ����һ�����ݽṹ,������һ����ȫ������
    �������Ĺ���Ϊ,����һ�����ڵ㶼���������ӽڵ�
    ���ȶ��п��Ի������������������������ʵ��

    �������������������ñȽϴ�С,���³�����ʱ�����½�������,��Ȼ�ϸ��ڼ�û�бȽ���������

    ����Ԫ��LogN,ȡ��Ԫ��LogN
*/

//���ڶѵ����ȶ���
template<class Type>
class SimpleMaxPq {
public:
    SimpleMaxPq():m_vec(1,0) {}
    ~SimpleMaxPq() {}
    //����k��Ԫ�ؽ����ϸ�
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
    //����k��Ԫ���³�
    void sink(size_t k){
        while(2*k < m_vec.size()){
            //�ҵ���һ���ӽڵ�      1���ӽڵ���2,3, 2���ӽڵ��� 4,5 
            size_t _idx = 2*k;
            //Ҫ�Ƚϵ��������ӽڵ�
            //vec[1] Ҫ�Ƚ� vec[2]��vec[3],������������ȱȽ�2��3ȡ�����
            if(_idx < m_vec.size() && less(_idx, _idx + 1)){
                _idx++;
            }
            //���жϳ����Ľڵ����ָ���ڵ�ʱ,���н���,�����ж�ѭ��
            if(!(m_vec[k] < m_vec[_idx])){
                break;
            }
            std::swap(m_vec[k], m_vec[_idx]);
            //�����ɹ�,����������λ���ٴν����ж�
            k = _idx;
        }
    }

    //�����ȶ��в���
    void insert(Type v){
        m_vec.push_back(v);
        //����Ԫ�غ�,�����һ��Ԫ�ؽ����ϸ�����
        swim(m_vec.size()-1);
    }

    void size(){
        //Ϊ0���±겻ʹ��
        return m_vec.size()-1;
    }

    Type delMax(){
        //�Ȼ�ȡ��ǰ���ֵ
        Type _rst = m_vec[1];
        //�����뵱ǰ��Сֵ���н���
        std::swap(m_vec[1],m_vec[m_vec.size()-1]);
        //ɾ�����ó������ֵ
        m_vec.erase(m_vec.end()-1);
        //Ȼ�󽫵�ǰλ��Ϊ1��ֵ������Ǳ
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
        //�ҵ���һ���ӽڵ�      1���ӽڵ���2,3, 2���ӽڵ��� 4,5 
        size_t _idx = 2 * k;
        //Ҫ�Ƚϵ��������ӽڵ�
        //vec[1] Ҫ�Ƚ� vec[2]��vec[3],������������ȱȽ�2��3ȡ�����
        if (_idx < n && less(m_vec, _idx, _idx + 1)) {
            _idx++;
        }
        //���жϳ����Ľڵ����ָ���ڵ�ʱ,���н���,�����ж�ѭ��
        if (!(m_vec[k] < m_vec[_idx])) {
            break;
        }
        std::swap(m_vec[k], m_vec[_idx]);
        //�����ɹ�,����������λ���ٴν����ж�
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