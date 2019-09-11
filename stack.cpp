#include<iostream>

using namespace std;

class Stack{
    char arr[20];
    int top;
    public:
    Stack(){
        top =-1;
    }
    bool isEmpty(){return top==-1 ?true:false;}
    bool isFUll(){return top==19 ? true: false;}
    void push(char k){
        if(!isFUll())
            arr[++top]=k;
    }
    char pop(){
        if(!isEmpty())
            return arr[top--];
        
    }
    void check(string s){
        int n=s.length();
        int i=0;
        if(s[i]=='}'|| s[i]==']'|| s[i]==')'){
            cout<<"Enter valid expression\n";
            return;
        }
        while(n--)
        {
            if(s[i]=='{'|| s[i]=='['|| s[i]=='('){
                push(s[i]);
            }
            if(s[i]=='}'|| s[i]==']'|| s[i]==')'){
                if(isEmpty()){
                    cout<<"Number of opening brackets is less\n\a";
                    return;
                }
                char temp;
                temp=pop();
                if(temp=='(' && s[i]!=')' || temp=='[' && s[i]!=']'||temp=='{' && s[i]!='}'){
                    cout<<"Bracket error\n\a";
                    return;
                }
            }
            i++;
        }
        if(!isEmpty()){
            cout<<"Number of closing  brackets is less\n";
            return;
        }
        cout<<"\nStable Equation\n\n";

    }
};



int main()
{
    Stack s;
    cout<<"EQUATION CHECKER\n";
    char c;
    do{
        string p;
        cout<<"Enter the equation\n>>";
        cin>>p;
        s.check(p);
        cout<<"Do you want to continue\n>>";
        cin>>c;

    }while(c=='y');
    return 0;
}