#include <iostream>
#include <vector>

template<class T> void sort(std::vector<T>& v){
    T temp;
    for(long unsigned int i = 0; i < v.size(); ++i){
        for(long unsigned int j = 0; j < (v.size() - i - 1); j++){
            if(v[j] > v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}
auto main() -> int{
    int x;
    std::vector<int> v;
    while(std::cin >> x)
        v.push_back(x);
    sort<int>(v);
    for(const auto& i : v)
        std::cout << i << std::endl;
}