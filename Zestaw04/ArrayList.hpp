#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
#define DEF_SIZE 10000


template<class T>
class ArrayList{
    private:
        T * array;
        int _size;
        int capacity;
    public:
        ArrayList(); 
        ArrayList(int size);
        ~ArrayList();
        void push_front(T x);
        T pop_front();
        void push_back(T x);
        T pop_back();
        int size();
        bool empty();
        void clear();
        int find(T x);
        T erase(int i);
        void insert(int i, T x);
        int remove(T x);
        bool replace(T x, T y);
        
};

template<class T>
ArrayList<T>::ArrayList(){
    array = new T[DEF_SIZE];
    capacity = DEF_SIZE;
    _size = 0;
}

template<class T>
ArrayList<T>::ArrayList(int size){
    array = new T[size];
    capacity = size;
    _size = 0;
}

template<class T>
ArrayList<T>::~ArrayList(){
    delete[] array;
    _size = 0;
}


template<class T>
void ArrayList<T>::push_front(T x){
    if(_size == capacity){
        throw std::out_of_range("FULL");
    }
    for(int i = size() ; i > 0; i--){
        array[i] = array[i-1];
    }
    array[0] = x;
    _size++;

}


template<class T>
T ArrayList<T>::pop_front(){
    if(empty()){
        throw std::out_of_range("EMPTY");
    }
    T output = array[0];
    for(int i = 0; i< size() - 1; ++i){
        array[i] = array[i+1];
    }
    _size--;
    return output;
}


template<class T>
void ArrayList<T>::push_back(T x){
    if(_size == capacity){
        throw std::out_of_range("FULL");
    }
    else{
        array[_size++] = x;
    }
}

template<class T>
T ArrayList<T>::pop_back(){
    if(empty()){
        throw std::out_of_range("EMPTY");
    }
    return array[--_size];
}

template<class T>
int ArrayList<T>::size(){
    return _size;
}

template<class T>
bool ArrayList<T>::empty(){
    return (_size == 0);
}

template<class T>
void ArrayList<T>::clear(){
    delete[] array;
    T array = new T[capacity];
    _size = 0;
}

template<class T>
int ArrayList<T>::find(T x){
    for(int i = 0; i < _size; ++i){
        if(array[i] == x)
            return i;
    }
    return -1;
}

template<class T>
T ArrayList<T>::erase(int i){
    T output;
    if(empty())
        throw std::out_of_range("EMPTY");
    else{
        output = array[i];
        for(int n = i; n < _size; ++n){
            array[n] = array[n+1];
        }
    }
    return output;
}

template<class T>
void ArrayList<T>::insert(int i, T x){
    for(int n = _size + 1; n > i; n--){
        array[n] = array[n-1];
    }
    array[i] = x;

}

template<class T>
int ArrayList<T>::remove(T x){
    int counter = 0;
    for(int i = 0; i < _size; i++){
        if(counter > 0)
            array[i - counter] = array[i];
        if(array[i] == x)
            counter++;
    }
    _size = _size - counter;
    return counter;
}

template<class T>
bool ArrayList<T>::replace(T x, T y){
   for(int i = 0; i < _size; ++i){
        if(array[i] == x){
            array[i] = y;
            return true;
        }
    }
    return false;
}



#endif



