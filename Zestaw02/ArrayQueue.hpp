#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H



class Queue{
    public:
        Queue(int size);
        ~Queue();
        void push(int x);
        int pop();
        int size();
        bool empty();
    private:
        int capacity;
        int* Q;
        int front; 
        int rear; 
        int n; 
};

Queue::Queue(int size){
    capacity = size;
    front = rear = -1;
    n = 0;
    Q = new int[size];
}

Queue::~Queue(){delete[] Q;}

int Queue::size(){
    return n;
}

bool Queue::empty(){
    return (n == 0);
}
int Queue::pop(){
    if(empty()){
        throw std::out_of_range("EMPTY");
    }
    int temp = Q[front];
    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front+1)%capacity;
    }
    n--;
    return temp;
}

void Queue::push(int x){
    if(empty())
        front++; 
    rear = (rear+1)%capacity;
    Q[rear] = x;
    n++;
}

#endif