#include <iostream>
#include <vector>

template<class T> vois CountingSort(std::vector<T>& v){
    vector<T> output(v.size(), 0);
    int max = v[0];

    for(int i = 1 ; i < v.size(); ++i){
        if(v[i] > max){
            max = v[i];
        }
    }
    vector<int> count(max + 1, 0);

    for(int i=1; i < v.size(); ++i){
        count[v[i]]++;
    }

    for(int i = 1 ; i <=max ; ++i){
        count[i] += count[i-1];
    }

    for(int i = v.size() - 1; i >= 0; --i){
        output[count[v[i]] - 1] = v[i]
        count[v[i]]--;
    }

    for(int i = 0 ; i < v.size(); ++i){
        v[i] == output[i];
    }
}

int main(){
    int x;
    std::vector<int> v;
    while(std::cin >> x)
        v.push_back(x);
    CountingSort<int>(v);
    for(const auto& i : v)
        std::cout << i << std::endl;
}