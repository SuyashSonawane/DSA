#include <iostream>
using namespace std;
/*
Author : Suyash Sonawane 
Assignment No: 1
Queston:
    Write C/C++ program to store marks scored for first test of subject 'Data Structures and
    Algorithms' for N students. Compute
    I. The average score of class
    ii. Highest score and lowest score of class
    iii. Marks scored by most of the students
    iv. list of students who were absent for the test
 */
class Students{
    // CLASS for STUDENTS
    public:
    string name;
    int DSA_Marks,roll_no,isPresent;
};
class Class{
    // CLASS for CLASS 
    public:
    int strength,high=0,low=100,enterred_stu=0 ,count[10],m=0;
    Students students[100];
    Class(int s){
        strength =s;
        while(m<10){
        count[m]=0;
        m++;
        };
    };
    void addStudents(){
        //  functions for adding students 
        int n,i=0,k=0;
        char isPresent;
        cout << "How many students do you want to add::=>";
        cin >> n;
        while(i<n){
            cout<<"\nStudent "<<i+enterred_stu+1;
            cout << "Enter name : ";
            cin >> students[i+enterred_stu].name;
            cout <<"Enter rollno : ";
            cin >> students[i+enterred_stu].roll_no;
            cout << "Is the student present (n/y)";
            cin >> isPresent;
            if(isPresent=='y'){
                students[i+enterred_stu].isPresent=1;
                cout << "Enter DSA Marks of:=> ";
                cin >> students[i+enterred_stu].DSA_Marks;
                count[(students[i+enterred_stu].DSA_Marks)/10]++;
                if(students[i+enterred_stu].DSA_Marks>high)
                    high =students[i+enterred_stu].DSA_Marks;
                if(students[i+enterred_stu].DSA_Marks<low)
                    low=students[i+enterred_stu].DSA_Marks;
            }
            else
            {
                if(isPresent=='n'){
                    students[i+enterred_stu].DSA_Marks=-1;
                    students[i+enterred_stu].isPresent=0;

                }
                

            }
            i++;
        }
        enterred_stu+=n;
    }
    void average(){
        //  function for calculating average
        float sum=0,avg;
        for(int j=0;j<enterred_stu;j++){
            if(students[j].isPresent)
                sum += students[j].DSA_Marks;
        }
        cout <<"The average marks are:: "<<(sum/enterred_stu);

    }
    void absent(){
        // function for displaying absent students
        cout<<"\tName\tRoll No\n";
        for(int j; j< enterred_stu;j++){
            if(!students[j].isPresent){
                cout << "\t"<<students[j].name << "\t"<<students[j].roll_no<<endl;
            }
        }
    }
    void getrange(){
        //  function for showing range of students
        int max= 0,index;
        for(int b =0;b<10;b++){
            if(count[b]>max){
                max=count[b];
                index=b;
            }
                
        }
        cout<<"Out of "<< strength<<" students "<<max<<" students scored marks in range of "<< index*10<<" to "<<(index*10)+9<< endl;
        
    }

};

int main()
{
    int n,i,k=1;
    cout << "Enter the strenght of the class || MAX:100\n::=> ";
    cin >> n;
    Class B(n); // creating class object
    //  menu driven logic
    do{    
        cout << "\n\nWhat do you want to do?\n1.Add Students\n2.Average score of the class\n3.Highest score and lowest score of class\n4.Marks scored by most of the students\n5.list of students who were absent for the test\n99.Exit\n::=>";
        cin >> i;
        switch(i){
            case 1:
                B.addStudents();
                break;

            case 2:
                B.average();
                break;

            case 3:
                cout<<"Highest Score ; "<<B.high <<endl;
                cout <<"Lowest Score : "<<B.low;
                break;

            case 4:
                B.getrange();
                break;

            case 5:
                B.absent();
                break;
            case 99:
                k=0;
                break;
            default:
                cout<<"Enter correct option!!";
        }
        
    }
    while(k);


    

}