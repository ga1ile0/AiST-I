#include <iostream>
#include <vector>
#include <cmath>
#include "LinkedQueue.hpp"


void radix(std::vector<int> &v){
    LinkedQueue bins[10];
    int num_of_digits = 9;
    int current_digit = 0;

    while(current_digit < num_of_digits){
        for(long unsigned int i = 0; i < v.size(); ++i){
            int divisor = pow(10, current_digit);
            int digit = ((v[i]/divisor)%10);
            bins[digit].push(v[i]);
        }

        v.clear();

        for(int k=0; k < 10; ++k){
            while(!bins[k].empty()){
                v.push_back(bins[k].pop());
            }
        }
        current_digit++;

    }
}

int main(){
    int x;
    std::vector<int> v;

    while(std::cin>>x)
        v.push_back(x);

    radix(v);
    
    for(const auto& i : v){
        std::cout << i << std::endl;
    }
    return 0;
}