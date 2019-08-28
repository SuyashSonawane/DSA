#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
class Chain{
    node *head, *tail;
    public:
    Chain(){
        head=NULL;
    }
    void push(){
        int data;
        cout<<"\nEnter the node value\n>>";
        cin >>data;
        node *n = new node;
        n->data=data;
        n->next=NULL;
        if(head==NULL){
            head = n;
            tail =n;
        }
        else
        {
            tail->next=n;
            tail = tail->next;
        }
    }
    void display(){
        node *temp;
        temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    void insert_after(){
        int target,data;
        cout<<"\nEnter the value to insert after\n>>";
        cin>>target;
        if(findNodeByValue(target)){
            cout<<"\nEnter the value\n>>";
            cin>>data;
            node *newNode = new node;
            node *temp;
            temp = head;
            newNode->data=data;
            while (temp->data!=target)
            {
                temp=temp->next;
            }
            node *cl;
            cl=temp->next;
            newNode->next=cl;
            temp->next=newNode;
        }
        else
        {
                cout<<"\nNode of this value is not available\n";
        }
        


    }
    void insert_at(){
        int index,data;
        cout<<"\nEnter the index to insert at\n>>";
        cin>>index;
        if(index<=maxIndex()){
            cout<<"\nEnter the value\n>>";
            cin>>data;
            node *newNode = new node;
            node *temp;
            int k=0;
            temp = head;
            newNode->data=data;
            while (k!=index)
            {
                temp=temp->next;
                k++;
            }
            node *cl;
            cl=temp->next;
            newNode->next=cl;
            temp->next=newNode;
        }
        else{
            cout<<"\nEntered index out of bound\a\n";
        }


    }
    void update(){
        int target,data;
        cout<<"\nEnter the value of node to update\n>>";
        cin>>target;
        if(findNodeByValue(target)){
            cout<<"\nEnter the value\n>>";
            cin>>data;
            node *temp;
            temp = head;
            while (temp->data!=target)
            {
                temp=temp->next;
            }
            temp->data=data;
        }
        else
        {
            cout<<"\nNode not found\n\a";
        }       


    }
    void del(){
        int target;
        cout<<"\nEnter the value delete\n>>";
        cin>>target;
        if(findNodeByValue(target)){
            node *temp,*deltemp;
            temp = head;
            if(head->data==target){
                head=head->next;
            }
            else{
                while (temp->next->data!=target)
                {
                    temp=temp->next;
                }
                deltemp=temp->next;
                temp->next = temp->next->next;
                delete deltemp;

            }
        }
        else
        {
            cout<<"\nCannot find the node for deletion \n\a";
        }
        


    }
    bool isEmpty(){
        return head==NULL ? true:false; 
    }
    bool findNodeByValue(int value){
        node *temp;
        temp = head;
        while (temp!=NULL)
        {
            if(temp->data==value)
                return true;
            temp=temp->next;
        }
        return false;
    }
    int maxIndex(){
        int count=0;
        node *temp;
        temp = head;
        while (temp->next!=NULL)
        {
            count ++;
            temp=temp->next;
        }
        return count;
    }
    void operator+(Chain c){
        node *temp;
        temp = head;
        while(temp!=NULL){
            temp=temp->next;
        }
        temp->next=c.head;
    }



};


int main(){
    Chain B;
    int m=1,u_input;
    do{
        cout<<"\n1.Push Nodes\n";
        if(!B.isEmpty())
            cout<<"2.Insert Node at index\n3.Insert node after a node\n4.Delete node using value\n5.Update Node\n6.Display LL\n";
        cout<<"99.Exit Program\n>>";
        cin>>u_input;
        
        switch (u_input)
        {
        case 1:
            int a,value;
            cout<<"\nEnter number of nodes to insert\n>>";
            cin>>a;
            for(int b=0;b<a;b++){
                B.push();
            }
            break;
        case 2:
            if(!B.isEmpty())
            B.insert_at();
            break;
        case 3:
            if(!B.isEmpty())
            B.insert_after();
            break;
        case 4:
            if(!B.isEmpty())
            B.del();
            break;
        case 5: 
            if(!B.isEmpty())          
            B.update();
            break;
        case 6:
          if(!B.isEmpty()){
            cout<<endl;
            B.display();
            cout<<endl;
            }
            break;
        case 99:
           m=0;
            break;
        default:
            break;
        }
    }
    while(m);
}