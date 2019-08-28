#include<iostream>
using namespace std;


void password(string it, string ot){
    if(it.length()==0){
        // if(ot.length()==4)
            cout << ot<< endl;
        return;
    }
    password(it.substr(1),ot);
    password(it.substr(1),ot+it[0]);

}


int main(){

    password("13asti","");
    return 0;
}