#include <iostream>
#include <string>
#include "LinkedQueue.hpp"
#include "ArrayQueue.hpp"

#define SIZE 1000000

using namespace std;

int main(){

    //Queue my_queue(SIZE);
    LinkedQueue my_queue;
    string operation;
    int n;
    int x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> operation;
        if(operation == "A"){
            cin >> x;
            my_queue.push(x);
        }
        else if(operation == "D"){
            try{
                cout << my_queue.pop() << endl;
            }
            catch(std::out_of_range &e){
                cout << e.what() << endl;
            }
        }
        else if(operation == "S"){
            cout << my_queue.size() << endl;
        }
    }
}
