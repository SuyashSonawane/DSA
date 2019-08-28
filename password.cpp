#include<iostream>
using namespace std;


void password(string s,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++)
            // if(s.substr(j).length()==4)
                cout<<s.substr(i+j)<<endl;
    }

}


int main(){
    string s="13asti";
    password(s,s.length());
    return 0;
}