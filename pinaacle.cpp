#include<iostream>
using namespace std;

struct node{
    int PRN;
    string name;
    node *next;
};
class Chain{
    node *President,*Secerety;
    public:
    Chain(){
        President=NULL;
        Secerety=NULL;
    }
    void push(){
        int PRN;
        string name;
        cout<<"Enter the name\n>>";
        cin >>name;
        cout<<"Enter PRN\n";
        cin>>PRN;
        node *n = new node;
        n->name=name;
        n->PRN=PRN;
        n->next=Secerety;
        if(President==NULL){
            President = n;
            Secerety =n;
        }
        else
        {
            Secerety->next =n;
            Secerety = Secerety->next;
        }
    }
    void president(){
        int PRN;
        string name;
        cout<<"Enter the name\n>>";
        cin >>name;
        cout<<"Enter PRN\n";
        cin>>PRN;
        President->name=name;
        President->PRN=PRN;
        President->next=NULL;
    }
    void Secerty(){
        node *n=new node;
        int PRN;
        string name;
        cout<<"Enter the name\n>>";
        cin >>name;
        cout<<"Enter PRN\n";
        cin>>PRN;
        Secerety->PRN=PRN;
        n->name=name;
        n->PRN=PRN;
        n->next=NULL;
        President->next=n;
    }
    void display(){
        node *temp;
        temp = President;
        while(temp!=Secerety){
            cout<<temp-> name <<" " <<temp->PRN<<endl;
            temp=temp->next;        }
        cout<<temp-> name <<" " <<temp->PRN<<endl;            
        
        cout<<"\n"; 
    }
    void insert_after(){
        string name;
        int PRN;
        cout<<"\nEnter the name\n>>";
        cin>>name;       
        cout<<"\nEnter the PRN\n>>";
        cin>>PRN;
        node *newNode = new node;
        node *temp;
        temp = President;
        newNode->name=name;
        newNode->PRN=PRN;
        while (temp->next->PRN!=Secerety->PRN)
        {
            temp=temp->next;
        }
        node *cl;
        cl=temp->next;
        newNode->next=cl;
        temp->next=newNode;
    }
        


    // }
    // void insert_at(){
    //     int index,data;
    //     cout<<"\nEnter the index to insert at\n>>";
    //     cin>>index;
    //     if(index<=maxIndex()){
    //         cout<<"\nEnter the value\n>>";
    //         cin>>data;
    //         node *newNode = new node;
    //         node *temp;
    //         int k=0;
    //         temp = head;
    //         newNode->data=data;
    //         while (k!=index)
    //         {
    //             temp=temp->next;
    //             k++;
    //         }
    //         node *cl;
    //         cl=temp->next;
    //         newNode->next=cl;
    //         temp->next=newNode;
    //     }
    //     else{
    //         cout<<"\nEntered index out of bound\a\n";
    //     }


    // }
    // void update(){
    //     int target,data;
    //     cout<<"\nEnter the value of node to update\n>>";
    //     cin>>target;
    //     if(findNodeByValue(target)){
    //         cout<<"\nEnter the value\n>>";
    //         cin>>data;
    //         node *temp;
    //         temp = head;
    //         while (temp->data!=target)
    //         {
    //             temp=temp->next;
    //         }
    //         temp->data=data;
    //     }
    //     else
    //     {
    //         cout<<"\nNode not found\n\a";
    //     }       


    // }
    void del(){
        int target;
        cout<<"\nEnter the PRN delete\n>>";
        cin>>target;
        if(findNodeByValue(target)){
            node *temp,*deltemp;
            temp = President;
            if(President->PRN==target){
                President=President->next;
            }
            else{
                while (temp->next->PRN!=target)
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
        return President==NULL ? true:false; 
    }
    bool findNodeByValue(int value){
        node *temp;
        temp = President;
        while (temp!=NULL)
        {
            if(temp->PRN==value)
                return true;
            temp=temp->next;
        }
        return false;
    }
    int maxIndex(){
        int count=2;
        node *temp;
        temp = President;
        while (temp->next!=Secerety)
        {
            count ++;
            temp=temp->next;
        }
        return count;
    }
    // void operator+(Chain c){
    //     node *temp;
    //     temp = head;
    //     while(temp!=NULL){
    //         temp=temp->next;
    //     }
    //     temp->next=c.head;
    // }



};


int main(){
    int u_input;
    Chain B;
    B.president();
    // B.Secerty();
    B.insert_after();
    B.insert_after();
    B.display();

    // do{
    //     cout<<"\n1.Add Students\n";
    //     if(!B.isEmpty())
    //         cout<<"2.Insert Node at index\n3.Insert node after a node\n4.Delete node using value\n5.Update Node\n6.Display LL\n";
    //     cout<<"99.Exit Program\n>>";
    //     cin>>u_input;
        
    //     switch (u_input)
    //     {
    //     case 1:
    //         int a,value;
    //         cout<<"\nEnter number of students to insert\n>>";
    //         cin>>a;
    //         for(int b=0;b<a;b++){
    //             B.push();
    //         }
    //         break;
    //     // case 2:
    //     //     if(!B.isEmpty())
    //     //     B.insert_at();
    //     //     break;
    //     // case 3:
    //     //     if(!B.isEmpty())
    //     //     B.insert_after();
    //     //     break;
    //     // case 4:
    //     //     if(!B.isEmpty())
    //     //     B.del();
    //     //     break;
    //     // case 5: 
    //     //     if(!B.isEmpty())          
    //     //     B.update();
    //     //     break;
    //     case 6:
    //       if(!B.isEmpty()){
    //         cout<<endl;
    //         B.display();
    //         cout<<endl;
    //         }
    //     //     break;
    //     // case 99:
    //     //    m=0;
    //     //     break;
    //     default:
    //         break;
    //     }
    // }
    while(1);
}