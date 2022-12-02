#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include <iostream>

template<class T>
class BinaryTree{
    private:
    struct Node<T>{
        T obj;
        Node* left;
        Node* right;
    }
    Node * root;
    int size_;
    public:
        BinaryTree();
        ~BinaryTree();
        void insert(T x);
        Node* search(T x);
        Node* searchRecursive(T x);
        int size();
        vector<T> minimum();
        vector<T> maximum();
        int depth();
        vector<T> inorder();
        vector<T> preorder();
        vector<T> postorder();
}

template<class T>
BinaryTree<T>::BinaryTree(){
    int size_ = 0;
    root.left = nullptr;
    root.right = nullptr;
}

template<class T>
BinaryTree<T>::~BinaryTree(
    int size_ = 0;
    root.left = nullptr;
    root.right = nullptr;
)

template<class T>
void BinaryTree<T>::insert(T x){

}

template<class T>
Node* BinaryTree<T>::search(T x){

}

template<class T>
Node* BinaryTree<T>::searchRecursive(T x){

}

template<class T>
int BinaryTree<T>::size(){
    return (size_ == 0);

}

template<class T>
vector<T> BinaryTree<T>::minimum(){

}

template<class T>
vector<T> BinaryTree<T>::maximum(){

}

template<class T>
int BinaryTree<T>::depth(){

}

template<class T>
vector<T> BinaryTree<T>::inorder(){

}

template<class T>
vector<T> BinaryTree<T>::preorder(){

}

template<class T>
vector<T> BinaryTree<T>postorder(){

}

#endif