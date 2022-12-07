#ifndef CURSOR_LIST_H
#define CURSOR_LIST_H

#include <iostream>
#define DEF_SIZE 10000

template<class T>
class CursorList{
    private:
        struct Node{
            T value;
            int next;
        };
        Node * array;
        int head;
        int tail;
        int spare;
        int _size;
        int capacity;
    public:
        CursorList();
        CursorList(int size);
        ~CursorList();
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
CursorList<T>::CursorList(){
    array = new Node[DEF_SIZE];
    capacity = DEF_SIZE;
    for(int i = 0; i < capacity; i++){
        array[i].next = i+1;
    }
    head = 0;
    tail = 0;
    spare = 0;
    _size = 0;
}

template<class T>
CursorList<T>::CursorList(int size){
    array = new Node[size];
    capacity = size;
    for(int i = 0; i < capacity; i++){
        array[i].next = array[i+1];
    }
    head = 0;
    tail = 0;
    spare = 0;
    _size = 0;
}

template<class T>
CursorList<T>::~CursorList(){
    delete[] array;
    _size = 0;
}

template<class T>
void CursorList<T>::push_front(T x){
    if(_size == capacity)
        throw std::out_of_range("FULL");
    int temp = head;
    head = spare; //nowy element bedzie w miejscu spare i zostanie nowa glowa
    array[head].value = x; //ustawiam wartosc nowego elementu
    spare = array[spare].next; //wyznaczam nowego spare'a
    array[head].next = temp; //przypinam poprzedni pierwszy element jako next nowej głowy

    _size++;

}

template<class T>
T CursorList<T>::pop_front(){
    if(empty())
        throw std::out_of_range("EMPTY");
    int temp = head;
    head = array[head].next; //przesuwam głowe na drugi element 
    array[temp].next = spare; //'usuniety' element ma wskazywac na miejsce w ktorym przed usunieciem znajdowal sie spare
    spare = temp; //ustawiam pierwsze wolne miejsce na miejsce usunietego elementu; teraz next spare wskazuje na inny wolny element (ten usuniety)
    _size--;
    if(_size == 0) //jesli lista jest pusta to head ma byc w tym samym miejscu w tablicy co spare
        head = spare;
    return array[temp].value;
}

template<class T>
void CursorList<T>::push_back(T x){
    if(_size == capacity)
        throw std::out_of_range("FULL");
    int temp = tail;
    tail = spare; //przesuwam tail na pierwsze wolne miejsce
    array[tail].value = x; //ustawiam wartosc nowego tail'a
    spare = array[spare].next; //wyznaczam nowego spare'a
    array[temp].next = tail; //ustawiam next'a poprzedniego taila na nowego taila

    _size++;
    
}

template<class T>
T CursorList<T>::pop_back(){
    if(empty())
        throw std::out_of_range("EMPTY");
    int temp = head;
    for(int i = 0; i < _size - 2; ++i){
        temp = array[temp].next;  //ustawiam temp na element 'przed' tail'em
    }
    array[tail].next = spare; //usuniety element ma wskazywac na miejsce w ktorym przed usunieciem znajdowal sie spare
    spare = tail; //ustawiam spare na miejsce usunietego elementy (dzieki linijce wyzej ten element juz wskazuje na inne wolne miejsce)
    tail = temp; //ustawiam tail na element 'wczesniejszy'
    _size--;
    return array[spare].value;
}

template<class T>
int CursorList<T>::size(){
    return _size;
}

template<class T>
bool CursorList<T>::empty(){
    return (_size == 0);
}

template<class T>
void CursorList<T>::clear(){
    for(int i=0; i< _size; ++i){
        array[i].value = 0; //
        array[i].next = array[i+1];
    }
    _size = 0;
}

template<class T>
int CursorList<T>::find(T x){
    int temp = head;
    for(int i = 0; i < _size; ++i){
        if(array[temp].value == x)
            return i;
        temp = array[temp].next;
    }
    return -1;
}

template<class T>
T CursorList<T>::erase(int i){ //deletes and returns i-th element
    if(empty())
        throw std::out_of_range("EMPTY");
    int temp = head;
    for(int n = 0; n < i - 1; ++n){
        temp = array[temp].next;
    } //now temp holds index of (i-1)-th element
    int prev_spare = spare;
    spare = array[temp].next; //spare ustawiam w miejsce usunietego elementu
    array[array[temp].next].next = prev_spare;//usuniety element ma wskazywac na poprzedniego spare
    array[temp].next = array[array[temp].next].next; //element przed usunietym ma wskazywac na element za usunietym
    _size--;
    return array[spare].value; //zwracam wartosc usunietego elementu

}

template<class T>
void CursorList<T>::insert(int i, T x){
    if(_size == capacity)
        throw std::out_of_range("FULL");
    int temp = head;
    for(int n = 0; n < i-2 ; n++){
        temp = array[temp].next;
    }
    array[spare].value = x;
    array[temp].next = spare;
    array[spare].next = array[temp].next;
    spare = array[spare].next;

}

template<class T>
int CursorList<T>::remove(T x){
    int counter;
    int prev_spare;
    int temp = head;
    for(int i = 0; i < size(); i++){
        if(array[temp].value == x){
            counter++;
            prev_spare = spare;
            spare = array[temp].next;
            array[array[temp].next].next = prev_spare;
            array[temp].next = array[array[temp].next].next;
            _size--;
        }
    }
    return counter;
}

template<class T>
bool CursorList<T>::replace(T x, T y){
    int temp = head;
    for(int i = 0; i < _size; ++i){
        if(array[temp].value == x){
            array[temp].value = y;
            return true;
        }
        temp = array[temp].next;
    }
    return false;
}


#endif