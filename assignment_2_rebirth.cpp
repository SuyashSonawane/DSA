#include<iostream>
using namespace std;

class Sport{
    public:
    string name;
    int total;
    int roll[50];
    Sport(string s_name){
        name=s_name;        
    }
    void populate(int n){
        int i=0;
        total =n;
        while(i<n){
            cout<<"enter roll of student "<<i+1<<" ";
            cin >> roll[i];
            i++;
        }
    }
    void details(){
        cout<<"Set name "<< name <<endl;
        cout<<"Number of entries "<<total<<endl;
        cout<<"Roll numbers ";
        display();
    }
    void display(){
        cout<< "{";
        for(int i=0;i<total;i++){
            cout<<roll[i]<<",";
        }
        cout<<"}"<<endl;
    }
    void only(Sport &s){
          cout<< "{";
         for(int i=0;i<total;i++){
            int counter=0,j=0;
            for(j=0;j<s.total;j++)
            {
                if(roll[i]==s.roll[j]){
                    counter=1;
                    break;
                }
            }
            if(!counter)
                cout<<roll[i]<<",";
        }
        cout<<"}";
    }
    void _and(Sport &s){
        cout<< "{";
         for(int i=0;i<total;i++){
            int counter=0,j=0;
            for(j=0;j<s.total;j++)
            {
                if(roll[i]==s.roll[j]){
                    counter=1;
                    break;
                }
            }
            if(counter)
                cout<<roll[i]<<",";
        }
        cout<<"}";
    }
    void both(Sport &s){
        cout<< "{";
        for(int i=0;i<total;i++){
            cout<<roll[i]<<",";
        }
          for(int i=0;i<s.total;i++){
            int counter=0,j=0;
            for(j=0;j<total;j++)
            {
                if(roll[i]==s.roll[j]){
                    counter=1;
                    break;
                }
            }
            if(!counter)
                cout<<s.roll[i]<<",";
        }
        cout<<"}";
    }
};





int main(){
    int TOTAL,Icricket,Ibadminton,Uinput;
    Sport cricket("cricket") ,badminton("badminton");
    cout<<"Total number of students in the class\n=>";
    cin >> TOTAL;
    cout <<"Enter number of student who play cricket";
    cin>> Icricket;
    cricket.populate(Icricket);
    cout <<"Enter number of student who play badminton";
    cin>> Ibadminton;
    badminton.populate(Ibadminton);


    do{
    cout<<"\n\nSet operations\n1.Students who play either cricket or badminton or both\n2.Students who play badminton and cricket both\n3.Students who only play cricket\n4.Students who only play badminton\n5.Number of students who play nothing\n6.Details of Sets\n=>";
    cin>>Uinput;

    switch (Uinput)
    {
    case 1:
        cricket.both(badminton);
        break;
    case 2:
        cricket._and(badminton);
        break;
    case 3:
        cricket.only(badminton);
        break;
    case 4:
        badminton.only(cricket);
        break;
    case 5:
        cout<<TOTAL-Icricket-Ibadminton;
        break;
    case 6:
        cricket.details();
        badminton.details();
        break;
    default:
        break;
    }

        
    }while(1);



}