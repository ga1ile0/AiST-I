#include <iostream>
#include <random>
#include <string>
using namespace std;

int main(int argc, char **argv){
    if(argc != 2){
        cout << "Not enough arguments.\n";
        return -1;
    }
    int n = atoi(argv[1]);
    string output;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> letter(0,2);
    std::uniform_int_distribution<> number(0,1000000);
    char letters[] = "ADS";
    char x;
    cout << n << endl;


    for(int i=0;i<n;++i){
        x = letters[letter(gen)];
        output.insert(0, 1, x);
        if(x == 'A'){
            output = output + " ";
            cout << output << number(gen);
        }
        else{
            cout << output;
        }
        cout << endl;
        output.clear();

    }

    

}