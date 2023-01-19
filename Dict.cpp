#include <iostream>
#include <fstream>
#include "Dict.hpp"

int main(int argc, char **argv){
    if(argc < 2){
        return -1;
    }
    Dict<std::string, std::string> dict;
    std::pair<std::string, std::string> Pair;

    ifstream myfile(argv[1]);
    while(myfile >> Pair.first >> Pair.second){
        dict.insert(Pair);
    }
    myfile.close();
    std::string key;
    while(std::cin >> key){
        if(dict.find(key))
            std::cout << dict[key] << std::endl;
        else
            std::cout << "-" << std::endl;
    }

}