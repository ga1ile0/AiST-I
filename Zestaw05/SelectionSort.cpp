#include <iostream>
#include <algorithm>
#include <vector>

template<class T> void sort(std::vector<T>& v){
    int loc, temp, min;
    for(long unsigned int i = 0; i < v.size() - 1; ++i){
        min = v[i];
        loc = i;
        for(long unsigned int j = i + 1; j < v.size(); j++){
            if(min > v[j]){
                min = v[j];
                loc = j;
            }
        }
        temp = v[i];
        v[i] = v[loc];
        v[loc] = temp;
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