#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_


#include <iostream>

struct Node{
    int data;
    Node *link;
};

class LinkedStack{
    private:
        Node *top;
        int count;
    public:
        LinkedStack();
        bool empty();
        int size();
        int pop();
        void push(int x);
};

LinkedStack::LinkedStack(){
    top = NULL;
    count = 0;
}

bool LinkedStack::empty(){
    return (count == 0);
}

int LinkedStack::pop(){
    if(!empty()){
        Node *ptr = top;
        int temp = top->data;
        top = top->link;
        delete(ptr);
        count--;
        return temp;
    }
    else{
        throw std::out_of_range("EMPTY");
        return -1;
    }
}

void LinkedStack::push(int x){
    Node *ptr = new Node();
    ptr->data = x;
    ptr->link = top;
    top = ptr;
    count++;
}

int LinkedStack::size(){
    return count;
}

#endif