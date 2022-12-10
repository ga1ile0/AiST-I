#ifndef BST_HPP
#define BST_HPP
#include <iostream>
#include <stack>
#include <algorithm>

template<typename T>
struct Node{
    T data;
    Node* left;
    Node* right;
    Node(T x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

template<class T>
class BinaryTree{
    private:
        Node<T>* root;
        int _size;
        void _preorder(Node<T>* node);
        int _depth(Node<T>* node);
    public:
        BinaryTree(){
            root = nullptr;
            _size = 0;
        }
        void insert(T x);
        Node<T>* search(T x);
        Node<T>* searchRecursive(T x);
        int size();
        T minimum();
        T maximum();
        int depth();
        void inorder(Node<T>* node);
        void preorder();
        void postorder(Node<T>* node);
};

template<class T>
void BinaryTree<T>::insert(T x){
    Node<T>* temp = root;
    if(root == nullptr){
        root = new Node<T>(x);
        _size++;
        return;
    }
    int _curDepth = 1;
    while(true){
        _curDepth++;
        if(x >= temp->data){
            if(temp->right == nullptr){
                temp->right = new Node<T>(x);
                _size++;
                break;
            }
            temp = temp->right;
        }
        else{
            if(temp->left == nullptr){
                temp->left = new Node<T>(x);
                _size++;
                break;
            }
            temp = temp->left;
        }
    }
}

template<class T>
Node<T>* BinaryTree<T>::search(T x){
    Node<T>* current = root;
    while(current != nullptr){
        if(current->data == x){
            return current;
        }
        else{
            if(x > current->data){
                current = current->right;
            }
            else{
                current = current->left;
            }
        }
    }
    return nullptr;
}

template<class T>
Node<T>* BinaryTree<T>::searchRecursive(T x){
    if(root == nullptr) return nullptr;
    if(root->data == x) return root;
    if(x < root->data) searchRecursive(root->left);
    if(x > root->data) searchRecursive(root->right);
}

template<class T>
int BinaryTree<T>::size(){
    return _size;
}

template<class T>
T BinaryTree<T>::minimum(){
    Node<T>* current = root;
    while(current->left!= nullptr){
        current = current->left;
    }
    return current->data;
}

template<class T>
T BinaryTree<T>::maximum(){
    Node<T>* current = root;
    while(current->right != nullptr){
        current = current->right; 
    }
    return current->data;
}

template<class T>
int BinaryTree<T>::_depth(Node<T>* node){
    if(node == nullptr) return 0;
    int left_height = _depth(node->left);
    int right_height = _depth(node->right);
    if(left_height > right_height)
        return left_height + 1;
    else
        return right_height + 1;
}

template<class T>
int BinaryTree<T>::depth(){
    _depth(root);
}

template<class T>
void BinaryTree<T>::inorder(Node<T>* node){
    if(node == nullptr)
        std::cout << node->data << std::endl;
    inorder(node->left);
    std::cout << node->data << std::endl;
    inorder(node->right);
    
}

template<class T>
void BinaryTree<T>::preorder(){
    _preorder(root);
}

template<class T>
void BinaryTree<T>::_preorder(Node<T>* node){
    if(node != nullptr){
        std::cout << node->data << std::endl;
        BinaryTree<T>::_preorder(node->left);
        BinaryTree<T>::_preorder(node->right);
    }
}

template<class T>
void BinaryTree<T>::postorder(Node<T>* node){
    if(node == nullptr)
        std::cout << node->data << std::endl;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << std::endl;
}

#endif
