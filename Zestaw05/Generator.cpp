#include <iostream>
#include <random>

int main(int argc, char **argv){
    if(argc != 3){
        std::cout << "Not enough arguments.\n";
        return -1;
    }
    int x;
    int n = atoi(argv[1]);
    int max = atoi(argv[3]);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> number(1, max);

    for(int i = 0; i < n; ++i){
        x = number(gen);
        std::cout << x << std::endl;
    }
}