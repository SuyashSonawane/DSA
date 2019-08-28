#include<iostream>
using namespace std;


struct node{
    string name;
    int PRN;
    node *next;
};

class Club{
    public:
    node *head = new node; // president
    node *tail = new node; // sectery
    int total=2;


    Club(){
        head->next=tail;
        cout<<"ENter name of president \n=>";
        cin>>head->name;
        cout<<"\nENter PRN \n=>";
        cin>>head->PRN;
        cout<<"\nEnter name of secrtry\n=>";
        cin>>tail->name;
        cout<<"Enter PRN\n=>";
        cin>>tail->PRN;
        tail->next=NULL;
    }
    void add(){
        total++;
        node * n= new node;
        node *temp=head;
        cout<<"Enter the name of the student\n=>";
        cin>>n->name;
        cout<<"Enter the PRN of the student\n=>";
        cin>>n->PRN;
        while(temp->next!=tail){
            cout<<temp->PRN;
            temp=temp->next;
        }
        n->next=tail;
        temp->next=n;      
              

    }
    void changePresident(){
        cout<<"Enter the name of the President";
        cin>>head->name;
        cout<<"ENter PRN";
        cin>>head->PRN;
    }
    void display(){
        cout<<endl;
        node *temp=head;
        while (temp!=NULL)
        {
            cout<<temp->name<<"\t"<<temp->PRN<<endl;
            temp=temp->next;
        }
        
    }
    void changeSecerty(){
        cout<<"Enter the name of the Sectery";
        cin>>tail->name;
        cout<<"ENter PRN";
        cin>>tail->PRN;
    }
    void cancel(){
        int target;
        cout<<"ENter prn number to be canceled";
        cin>>target;
        node *temp =head;
        node *del;
        if(head->PRN==target){
            cout<<"Every club needs an president\nLets elect new president";
            changePresident();
            return;
        }
        if(tail->PRN==target){
            cout<<"Every club needs an Secerty\nLets elect new president";
            changeSecerty();
            return;
        }
        while(temp->next->PRN!=target)
            temp=temp->next;
        del= temp->next;
        temp->next=temp->next->next;
        delete del;   

        

    }
    void reverse(node *temp){
        if(temp==NULL){
            return;
        }
        else
        {
            reverse(temp->next);
            cout<<temp->name<<"\t"<<temp->PRN<<endl;
        }
        
    }
    void concat(Club b){
        tail->next=b.head;
    }
    int count(){
        int m=0;
        node * temp=head;
        while(temp!=NULL){
            temp=temp->next;
            m++;
        }
        return m;
    }

};
int main(){
    Club pinnacle;
    int input;
    do{
        cout<<"1.Add members\n2.Cancel Membership\n3.Display\n4.Display reverse\n5.Merge Clubs\n6.Count Total Members\n=>";
        cin>>input;
        switch (input)
        {
        case 1:
            pinnacle.add();
            break;
        case 2:
            pinnacle.cancel();
            break;
        case 3:
            pinnacle.display();
            break;
        case 4:
            pinnacle.reverse(pinnacle.head);
            break;
        case 5:
        {

            Club p2;
            int n;
            cout<<"\nHow many memebers do you want to add\n";
            cin>>n;
            for(int i =0;i<n;i++)
                p2.add();
            pinnacle.concat(p2);
            cout<<"\nMerged\n";
        }
            break;
        case 6:
            cout<<"\nNumber of member in club : "<<pinnacle.count()<<endl;
        break;
        default:
            break;
        }   
    }
    while(1);

}