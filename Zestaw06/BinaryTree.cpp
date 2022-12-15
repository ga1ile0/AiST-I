#include <iostream>
#include "BinaryTree.hpp"

int main(){
    int n, x;
    BinaryTree<int> tree;
    std::cin >> n;
    while(n > 0){
        std::cin >> x;
        tree.insert(x);
        n--;
    }
    std::cout << tree.size() << " " << tree.depth() << " " << tree.minimum() << " " << tree.maximum() << std::endl;
    tree.preorder();
    for(int i = 1; i < 10; i++){
        if(tree.searchRecursive(i) == nullptr){
            std::cout << "No" << std::endl;
        }
        else{
            std::cout << "Yes" << std::endl;
        }
    }
}