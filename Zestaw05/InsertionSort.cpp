#include <iostream>
#include <vector>

template<class T> void sort(std::vector<T>& v){
    for(int i = 1; i < v.size(); ++i){
        int key = v[i];
        int j = i - 1;

        while(key < v[j] && j>= 0){
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = key;
    }
}

int main(){
    int x;
    std::vector<int> v;
    while(std::cin >> x)
        v.push_back(x);
    sort<int>(v);
    for(const auto& i : v)
        std::cout << i << std::endl;   
}