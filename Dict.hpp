#ifndef DICT_HPP
#define DICT_HPP
#include "LinkedList.hpp"
#include <iostream>

#define SIZE 100
#define MAX_SIZE 1000000;

template<class K, class V>
class Dict{
    using Pair = std::pair<K, V>;
    private:
        int _size;
        LinkedList<Pair> dictionary[SIZE];
        unsigned int Hash(std::string key);
    public:
        Dict(){ }
        void clear();
        bool insert(const Pair& p);
        bool find(const K& k);
        V& operator[](const K& k);
        bool erase(const K& k);
        int size();
        bool empty();
        void buckets();
};

template<class K, class V>
unsigned int Dict<K, V>::Hash(std::string key){
    unsigned int hash = 2166136261u;
    for(int i = 0; i < key.length(); i++){
        hash = (hash^key[i]) * 16777619u;
    }
    return hash%SIZE;
}

template<class K, class V>
void Dict<K, V>::clear(){
    for(int i = 0; i < SIZE; i++){
        dictionary[i].clear();
    }
}


template<class K, class V>
bool Dict<K, V>::insert(const Pair& p){
    int hash = Hash(p.first);
    if(!find(p.first)){
        dictionary[hash].push_back(p);
        _size++;
        return true;
    }

    for(typename LinkedList<Pair>::Iterator itr = dictionary[hash].begin(); itr != dictionary[hash].end(); itr++){
        if(p.first == itr->value.first){
            itr->value.second = p.second;
            return false;
        }
    }
    return false;
}

template<class K, class V>
bool Dict<K, V>::find(const K& k){
    int hash = Hash(k);
    for(typename LinkedList<Pair>::Iterator itr = dictionary[hash].begin(); itr != dictionary[hash].end(); itr++){
        if(k == itr->value.first)
            return true;
    }
    return false;
}

template<class K, class V>
V& Dict<K, V>::operator[](const K& k) {
    int hash = Hash(k);
    for(typename LinkedList<Pair>::Iterator itr = dictionary[hash].begin(); itr != dictionary[hash].end(); itr++){
        if(k == itr->value.first)
            return itr->value.second;
    }
    throw std::out_of_range("Key not found in dictionary.");
}

template<class K, class V>
bool Dict<K, V>::erase(const K& k){
    int hash = Hash(k);
    int n = 0;
    for(typename LinkedList<Pair>::Iterator itr = dictionary[hash].begin(); itr != dictionary[hash].end(); itr++){
        if(k == itr->value.first){
            dictionary[hash].erase(n);
            _size--;
            return true;
        }
        n++;
    }
    return false;
}


template<class K, class V>
int Dict<K, V>::size(){
    return _size;
}

template<class K, class V>
bool Dict<K, V>::empty(){
    return (_size == 0);
}

template<class K, class V>
void Dict<K, V>::buckets(){
    int longest = 0, shortest = MAX_SIZE;
    for(int i = 0; i < SIZE; i++){
        int size = dictionary[i].size();
        if(size > longest)
            longest = size;
        if(size < shortest)
            shortest = size;
    }
    std::cout << "# " << _size << " " << SIZE << " " << shortest << " " << longest << std::endl;
}

#endif