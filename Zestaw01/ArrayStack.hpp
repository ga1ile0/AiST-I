#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_
using namespace std;

class Stack{
    public:
        Stack (int capacity);
        void push(int x);
        int pop();
        int size();
        bool empty();
    private:
        int *array;
        int top = 0;
};

Stack::Stack(int capacity){
    array = new int[capacity];
}


bool Stack::empty(){
    return (top == 0);
}

int Stack::size(){
    return top;
}

void Stack::push(int x){
    array[top] = x;
    top++;
}

int Stack::pop(){
    if(!empty()){
        top--;
        return array[top];
    }
    else{
        throw std::out_of_range("EMPTY");
        return -1;
    }

}

#endif