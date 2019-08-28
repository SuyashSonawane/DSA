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
    public:
    string name;
    int DSA_Marks;
    void fill_info(int m){
        // cout << "Enter name : ";
        // cin >> name;
        cout << "Enter DSA Marks of "<< m <<":=> ";
        cin >> DSA_Marks;

    }
};
class Class{
    public:
    int strength;
    int avg_marks,topper,lowest;
    Students students[100];
    Class(int s){
        strength =s;
    };
    void addStudents(){
        int n,i=0;
        char is
        cout << "How many students do you want to add::=>";
        cin >> n;
        while(i<n){
            cout << "Is the "<< i+1 <<" student present (n/y)";
            cin >> isAbsent;
            if(isAbsent=='y'){
                cout << "Enter DSA Marks of "<< m <<":=> ";
                cin >> DSA_Marks;
            }
            else{
                DSA_Marks=-1;
            }
            students[i].fill_info(i+1);
            i++;
        }
    }
    void average(){
        int sum=0,avg;
        for(int j=0;j<strength;j++){
            sum += students[j].DSA_Marks;
        }
        cout <<"The average marks are:: "<<(sum/strength);

    }

};

int main()
{
    int n,i;
    cout << "Enter the strenght of the class || MAX:100\n::=> ";
    cin >> n;
    Class B(n);
    cout << "\nWhat do you want to do?\n1.Add Students\n2.Average score of the class\n3.Highest score and lowest score of class\n4.Marks scored by most of the students\n5.list of students who were absent for the test\n::=>";
    cin >> i;
    switch(i){
        case 1:
        B.addStudents();
        B.average();
        break;

         case 2:
        break;

         case 3:
        //  highest and lowest
        break;

        case 4:
        // marks scored
        break;

        case 5:
        // List of students
        break;

        default:
            cout<<"Enter correct option!!";
    }




}
