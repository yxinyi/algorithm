#pragma once
#include <iostream>
#include "../ApiAlgorithm.h"

template<class KEY, class VAL>
class BaseSymbolTable {
public:
    BaseSymbolTable(){};
    virtual ~BaseSymbolTable(){}
    virtual void put(KEY k, VAL v){}
    virtual VAL get(KEY k){return VAL();}
    virtual void deleteNode(KEY k){}
    virtual bool contains(KEY key){return true;}
    virtual bool isEmpety(){return true;}
    virtual int size(){return 0;}
    virtual KEY min(){return KEY();}
    virtual KEY max() { return KEY(); }
    virtual KEY floor(KEY key) { return KEY() ;}
    virtual KEY ceiling(KEY key) { return KEY(); }
    virtual int rank(KEY k){return 0;}
    virtual KEY select(int k) { return KEY(); }
    virtual void deleteMin(){}
    virtual void deleteMax(){}
    virtual int size(KEY lo, KEY hi){return 0;}
};

template<class KEY, class VAL>
class Node {
public:
    Node(KEY k, VAL v):m_key(k),m_val(v), m_left(nullptr), m_right(nullptr) {}
    KEY   m_key;
    VAL   m_val;
    Node* m_left, * m_right;
    int   N;
};

template<class KEY, class VAL>
class RBNode{
public:
    RBNode(KEY k, VAL v, bool b = false) :m_key(k), m_val(v), m_left(nullptr), m_right(nullptr), isRed(b) {}
    KEY   m_key;
    VAL   m_val;
    RBNode* m_left, *m_right;
    int   N;
    bool isRed;
};

template<class KEY, class VAL>
class BinarySortTree : public BaseSymbolTable<KEY,VAL> {
public:
    BinarySortTree() {}
    virtual ~BinarySortTree() {}

    void put(KEY k, VAL v) {
        root = put(root,k,v);
    }
    VAL get(KEY k) {
        return get(root,k);
    }

    bool contains(KEY k){
        return contains(root,k);
    }
    void deleteNode(KEY k){
        root = deleteNode(root,k);
    }

    void deleteMin() {
        root = deleteMin(root);
    }

    void deleteMax() {
        root = deleteMax(root);
    }
    KEY min(){
        Node<KEY, VAL>* _p = min(root);
        if(_p != nullptr){
            return _p->m_key;
        }
        return KEY();
    }

    KEY max() {
        if (Node<KEY, VAL>* _p = max(root)) {
            return _p->m_key;
        }
        return KEY();
    }

private:
    Node<KEY,VAL>* put(Node<KEY, VAL>* n, KEY k, VAL v){
        if(n == nullptr){
            return new Node<KEY, VAL>(k,v);
        }
        else if(k < n->m_key){
            n->m_left = put(n->m_left, k, v);
            return n;
        }
        else if(k > n->m_key){
            n->m_right = put(n->m_right, k, v);
            return n;
        }
        n->m_val = v;
        return n;
    }

    VAL get(Node<KEY, VAL>* n,KEY k) {
        if(n == nullptr){
            return VAL();
        }
        else if(n->m_key == k){
            return n->m_val;
        }
        else if(n->m_key > k){
            return get(n->m_left,k);
        }
        return get(n->m_right, k);
    }

    bool contains(Node<KEY, VAL>* n,KEY k) {
        if(!n){
            return false;
        }
        if(n->m_key == k){
            return true;
        }
        else if(n->m_key > k){
            return contains(n->m_left , k);
        }
        return contains(n->m_right, k);
    }

    Node<KEY, VAL>* min(Node<KEY, VAL>* n) {
        if(n == nullptr){
            return n;
        }
        if(n->m_left == nullptr){
            return n;
        }
        return min(n->m_left);
    }

    Node<KEY, VAL>* max(Node<KEY, VAL>* n) {
        if (n == nullptr) {
            return n;
        }
        if (n->m_right== nullptr) {
            return n;
        }
        return max(n->m_right);
    }

    Node<KEY, VAL>* deleteNode(Node<KEY, VAL>* n, KEY k) {
        if(!n){
            return n;
        }
        if(n->m_key < k){
            n->m_right = deleteNode(n->m_right,k);
            return n;
        }
        else if(n->m_key > k){
            n->m_left = deleteNode(n->m_left, k);
            return n;
        }
        if(n->m_right){
            Node<KEY, VAL>* _tmp = new Node<KEY, VAL>(*min(n->m_right));
            Node<KEY, VAL>* _right_p = deleteMin(n->m_right);
            _tmp->m_left = n->m_left;
            delete n;
            return _tmp;
        }
        else if(n->m_left){
            Node<KEY, VAL>* _tmp = n->m_left;
            delete n;
            return _tmp;
        }
        delete n;
        return nullptr;
    }


    Node<KEY, VAL>* deleteMin(Node<KEY, VAL>* n) {
        if(!n){
            return nullptr;
        }
        if(n->m_left){
            n->m_left = deleteMin(n->m_left);
            return n;
        }
        Node<KEY, VAL>* _rst_p = n->m_right;
        delete n;
        return _rst_p;
    }

    Node<KEY,VAL>* deleteMax(Node<KEY, VAL>* n){
        if(!n){
            return n;
        }
        if(n->m_right){
            n->m_right = deleteMax(n->m_right);
            return n;
        }
        Node<KEY, VAL>* _tmp_lp = n->m_left;
        delete n;
        return _tmp_lp;
    }
private:
    Node<KEY, VAL>* root;
};

/*
    红黑树可以看成一颗2-3树
    主要定义:
        1:红链接均为左链接
        2:没有任何一个节点同时和两条红链接先练;
        3:该树是完美黑色平衡的,即任意空间街到根节点的路径和是哪个的黑链接数量相同

*/
template<class KEY, class VAL>
class RedBlackTree : public BaseSymbolTable<KEY, VAL> {
public:
    RedBlackTree():isRed(false){}
    RBNode<KEY, VAL>* rotateLeft(RBNode<KEY, VAL>* n){
        RBNode<KEY, VAL>* _tmp = n->m_right;
        n->m_right = _tmp->m_left;
        _tmp->m_left = n;
        _tmp->isRed = n->isRed;
        n->isRed = true;
        return _tmp;
    }
    RBNode<KEY, VAL>* rotateRight(RBNode<KEY, VAL>* n) {
        RBNode<KEY, VAL>* _tmp = n->m_left;
        n->m_left = _tmp->m_right;
        _tmp->m_right = n;
        _tmp->isRed = n->isRed;
        n->isRed = true;
        return _tmp;
    }

    void filpColors(RBNode<KEY, VAL>* n){
        n->m_left->isRed = false;
        n->m_right->isRed = false;
        n->isRed = true;
    }

    void put(KEY k, VAL v){
        root = put(root, k, v);
        root->isRed = false;
    }
    VAL min() {
        if(RBNode<KEY, VAL>* _tmp_p = min(root)){
            return _tmp_p->m_key;
        }
        return VAL();
    }

private:
    RBNode<KEY, VAL>* put(RBNode<KEY, VAL>* n,KEY k ,VAL v){
        if(!n){
            return new RBNode<KEY,VAL>(k,v,true);
        }
        if(k < n->m_key){
            n->m_left = put(n->m_left, k, v);
        }else if(k > n->m_key){
            n->m_right = put(n->m_right, k, v);
        }else{
            n->m_val = v;
        }
        //当右链接是红链接,左链接不是红链接,需要进行左旋操作
        if((n->m_right&&n->m_right->isRed) && (n->m_left &&!n->m_left->isRed)){
            rotateLeft(n);
        }
        //当左链接是红链接,左结点的左链接是红链接,需要进行右旋
        if((n->m_left&&n->m_left->isRed) && (n->m_left->m_left&&n->m_left->m_left->isRed)){
            rotateRight(n);
        }
        //当左右链接都是红链接时需要进行通化处理
        if((n->m_left&&n->m_left->isRed)&& (n->m_right&&n->m_right->isRed)){
            filpColors(n);
        }
        return n;
    }


    RBNode<KEY, VAL>* min(RBNode<KEY, VAL>* n) {
        if(n->m_left){
            return min(n->m_left);
        }
        return n;
    }

private:
    RBNode<KEY, VAL>* root;
    bool isRed;
};
