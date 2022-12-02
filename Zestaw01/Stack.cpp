#include <iostream>
#include <string>
#include "ArrayStack.hpp"
#include "LinkedStack.hpp"

#define SIZE 1000000

using namespace std;

int main(){

    Stack stos(SIZE);
    //LinkedStack stos;
    string operation;
    int n;
    int x;
    cin >> n;
    if( (n < 0) || (n > 1000000)){
        cout << "Bledna liczba operacji!\n";
        return -1;
    }
    for(int i = 0; i < n; i++){
        cin >> operation;
        if(operation == "A"){
            cin >> x;
            stos.push(x);
        }
        else if(operation == "D"){
            try{
                cout << stos.pop() << endl;
            }
            catch(std::out_of_range &e){
                cout << e.what() << endl;
            }
        }
        else if(operation == "S"){
            cout << stos.size() << endl;
        }
    }
}
