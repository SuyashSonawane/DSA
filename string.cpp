#include<iostream>
using namespace std;

class Strings{
    public:
    string content;
    int length;
    friend ostream & operator << (ostream &,Strings );
    friend istream & operator >> (istream & ,Strings &);
    void print(){
        for(int i=0;i<content.length();i++)
        {
            cout<<content[i];
        }
        cout<<endl;
    }
    void operator +(Strings s){
        int l1 = s.content.length(),i=0,j=0;
        int l2 =content.length();
        char S[l1+l2];
        for( i;i<content.length();i++){
            S[i]=content[i];
        }
        for( j;j<content.length();j++){
            S[i+j]=s.content[j];
        }
        cout << S << endl;
    }
    void copy(string s){
        content = s;
    }
    void copy(Strings s){
        content =s.content;
    }
    bool operator ==(Strings s){
        if(content.length() != s.content.length())
            return false;
        else{
            for(int i=0;i<content.length();i++){
                if(content[i]!=s.content[i])
                    return false;
                    
            }
            return true;
        }

    }
    bool operator ==(string s){
        if(content.length() != s.length())
            return false;
        else{
            for(int i=0;i<content.length();i++){
                if(content[i]!=s[i])
                    return false;
                    
            }
            return true;
        }

    }
    void reverse(){
        int len =content.length()/2 +1;
        char temp ,first = content[0];
        for(int i=0;i<len;i++){
            temp=content[i];
            content[i]=content[content.length()-i-1];
            content[content.length()-i-1]=temp;
        }
    }
    void substring(){
        string s;
        cout<<"Enter the string to be found\n=>";
        cin>>s;
        int i,j,counter=0;
        for(i=0;i<content[i]!=NULL;i++){
            if(content[i]==s[0]){
                for(j=0;j<s[j]!=NULL;j++){
                    if(content[i+j]!=s[j])
                        break;
                }
                i=i+j-1;
                counter++;
            }
        }
        if(counter)
            cout<<"SUBSTRING FOUND\n";
        else
            cout<<"NO SUBSTRING FOUND\n";
        
        
    }
};
ostream & operator << (ostream & out ,Strings s){
    out << s.content;   
    return out;
}
istream & operator >> (istream & in ,Strings &s){
    in >> s.content; 
    s.length=s.content.length();
    return in;
}

int main(){
    Strings s1,s2;
    cin>>s1;
    // if(s1==s2)
    //     cout<<"EQUAL";
    // else
    //     cout<<"Not EQUAL";
    s1.substring();
    
    return 0;
}