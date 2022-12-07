#include <iostream>
#include <string>
#include "CursorList.hpp"

using namespace std;

int main(){

    CursorList<int> list;
    string operation;
    int n;
    int x, y;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> operation;
        if(operation == "F"){
            cin >> x;
            try{
                list.push_front(x);
            }
            catch(std::out_of_range &e){
                cout << e.what() << endl;
            }
        }
        else if(operation == "B"){
            cin >> x;
            try{
                list.push_back(x);
            }
            catch(std::out_of_range &e){
                cout << e.what() << endl;
            }
        }
        else if(operation == "f"){
            try{
                cout << list.pop_front() << endl;
            }
            catch(std::out_of_range &e){
                cout << e.what() << endl;
            }
        }
        else if(operation == "b"){
            try{
                cout << list.pop_back() << endl;
            }
            catch(std::out_of_range &e){
                cout << e.what() << endl;
            }
        }
        else if(operation == "R"){
            cin >> x;
            cin >> y;
            if(list.replace(x, y))
                cout << "TRUE" << endl;
            else
                cout << "FALSE" << endl;
        }
        else if(operation == "S"){
            cout << list.size() << endl;
        }
    }
}
