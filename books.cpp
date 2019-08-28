/*
Author : Suyash Sonawane 
Assignment No: 3

Department library has N books. Write C/C++ program to store the cost of books in array in
ascending order. Books are to be arranged in descending order of their cost. Write function
for
a) Reverse the contents of array without using temporary array.
b) Copy costs of books those with cost less than 500 in new array
c) Delete the duplicate entries using temporary array
d) Delete duplicate entries without using temporary array
e) Count number of books with cost more than 500.


 */

#include<iostream>
using namespace std;

class Book{
    public:
    string name;
}
;
class Library{
    public:
    int books_cost[100],nBooks;
    Library(int n){
        nBooks=n;
    }
    void sort(){
        for(int i=0;i<nBooks-1;i++){
            for(int j=0;j<nBooks-i-1;j++){
                if(books_cost[j]>books_cost[j+1])
                {
                    int temp = books_cost[j];
                    books_cost[j] =books_cost[j+1];
                    books_cost[j+1]=temp;

                }
            }
        }
    }
    void show(){
        for(int i=0;i<nBooks;i++){
            cout<<books_cost[i]<<endl;
        }
    }
    void show(int n){
        for(int i=0;i<n;i++){
            cout<<books_cost[i]<<endl;
        }
    }
    void reverse(){
        int len =nBooks/2 +1;
        int temp ;
        for(int i=0;i<len;i++){
            temp=books_cost[i];
            books_cost[i]=books_cost[nBooks-i-1];
            books_cost[nBooks-i-1]=temp;
        }
    }
    int copy(int money,int a[100]){
        int k=0;
        for(int i=0;i<nBooks;i++){
            if(books_cost[i]<money){
                a[k]=books_cost[i];
                k++;
            }
        }
        return k;

    }
    void makeZero(int arr[]){
        for(int m=0;m<nBooks;m++){
            arr[m]=0;
        }
    }
    int count(int money){
        int k=0;
        for(int i=0;i<nBooks;i++){
            if(books_cost[i]>money)
                k++;
        }
        return k;
    }
    int removeDublicatesTemp(){
        int temp[nBooks],k=0;
        makeZero(temp);
        for(int i=0;i<nBooks;i++){
            int flag=0;
           for(int j=0;j<nBooks;j++){
               if(books_cost[i]==temp[j])
                    flag=1;
           }
           if(!flag){
               temp[k++]=books_cost[i];
           }
       }
       makeZero(books_cost);

        for(int m=0;m<k;m++){
            books_cost[m]= temp[m];
        }
        return k;
    }
    int removeDublicates(){
        sort();
        int counter=0;
        for(int i =0;i<nBooks;i++){
            for(int j=i+1;j<nBooks;j++){
                if(books_cost[i]==books_cost[j])
                {
                    counter++;
                    for(int k=j;k<nBooks;k++){
                        books_cost[k]=books_cost[k+1];
                    }
                }
            }
        }
       return counter;
    }
};



int main(){
    int m[100],c,input;

    cout<<"Enter number of books you want to enter\n=> ";
    cin>>c;
    Library l1(c);
    for(int i=0;i<c;i++){
        cout<<"Enter the name of book "<<i+1<<"\n=> ";
        cin>>l1.books_cost[i];
    }
    do{
        cout<<"1) Reverse the contents of array without using temporary array.\n2) Copy costs of books those with cost less than 500 in new array\n3) Delete the duplicate entries using temporary array\n4) Delete duplicate entries without using temporary array\n5) Count number of books with cost more than 500.\n=> ";
        cin>>input;
        switch(input){
            case 1:
                l1.reverse();
                l1.show();
                break;
            case 2:
                l1.copy(500,m);
                for(int i=0;i<c;i++){
                    cout<<m[i]<<endl;
                }
                break;
            case
        }
    }
    


    return 0;
}