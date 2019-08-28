#include<iostream>
using namespace std; 

/*
    1:Badminton
    2:Cricket
    3:Both
    4:None

 */
class Students{
    public:
    string roll;
    int option;
};
class Group{
    int num,option;
    Students students[50];
    public:
    Group(){
        cout<<"How many students do you want to add\n::=>";
        cin>>num;
        accept_students(num);
    }
    private:
    void accept_students(int n){
        for(int i;i<n;i++){
            cout<<"Enter the roll of the student "<<i+1<<" :: ";
            cin>> students[i].roll;
            cout<<"\nWhat do he play\n1.Badminton\n2.Cricket\n3.Both\n4.None\n::=>";
            cin >> students[i].option;
        }
    }
    public:
    void displayAll(){
        cout << "roll\tSport\n";
        for(int j=0;j<num;j++){
            cout<<students[j].roll;
            if(students[j].option==1)
                cout<<"\tBadminton\n";
            else if(students[j].option==2)
                cout<<"\tCricket\n";
                else if(students[j].option==3)
                    cout<<"\tBoth\n";
                    else
                         cout<<"\tNone\n";

            
        }
    }
    void e_c_b_b(){ // either 1,2,3
        cout << "roll" << endl;
        for(int k =0;k<num;k++){
            if(students[k].option==1 || students[k].option==2 ||students[k].option==3){
                cout<< students[k].roll <<endl;
            }
        }
    }
    void b(){// both
        cout << "roll" << endl;
        for(int k =0;k<num;k++){
            if(students[k].option==3){
              cout<<  students[k].roll;
            }
        }
    }
    void onlyCricket(){// cricket
        cout << "roll" << endl;
        for(int k =0;k<num;k++){
            if(students[k].option==2){
               cout<< students[k].roll <<endl;
            }
        }
    }
    void onlyBadminton(){// cricket
        cout << "roll" << endl;
        for(int k =0;k<num;k++){
            if(students[k].option==1){
               cout<< students[k].roll <<endl;
            }
        }
    }
    void none(){// none
        cout << "roll" << endl;
        for(int k =0;k<num;k++){
            if(students[k].option==4){
              cout<< students[k].roll <<endl;
            }
        }
    }
    
};

int main(){
    int n=1,k;
    Group g;

    while(n){
        cout<<"\n1.Set of students who play either cricket or badminton or both\n2.Set of students who play both cricket and badminton\n3.Set of students who play only cricket\n4.Set of students who play only badminton\n5.Number of students who play neither cricket nor badminton\n99.Exit::=>";
        cin>>k;
        switch(k){
            case 1:
            g.e_c_b_b();
            cout<<endl;
            break;
            case 2:
            g.b();
            cout<<endl;
            break;
            case 3:
            g.onlyCricket();
            cout<<endl;
            break;
            case 4:
            g.onlyBadminton();
            cout<<endl;
            break;
            case 5:
            g.none();
            cout<<endl;
            break;
            case 99:
            k=0;
            default:
            cout<<"Enter correct option";
            cout<<endl;
        }
    }
    return 0;
}