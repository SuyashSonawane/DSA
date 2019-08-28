#include <iostream>
using namespace std;

struct node
{
    int bit;
    node *next, *previous;
};
class Binary
{
public:
    node *head = new node;
    node *tail;
    Binary()
    {
        head = NULL;
    }
    bool check(int m)
    {
        return m == 1 || m == 0 ? true : false;
    }
    void push()
    {
        cout << "Enter Binary number bit by bit below\n>>";
        int _bit;
        char ans;
        do
        {
            cin >> _bit;
            if (!check(_bit))
            {
                cout << "Enter only 1/0\a\n";
                return;
            }
            if (head == NULL && check(_bit))
            {
                node *n = new node;
                n->next = NULL;
                n->previous = NULL;
                n->bit = _bit;
                head = n;
                tail = head;
            }
            else if (check(_bit))
            {
                node *n = new node;
                n->next = NULL;
                n->previous = NULL;
                n->bit = _bit;
                node *temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                n->previous = temp;
                temp->next = n;
                tail = n;
            }
            cout << "Do you want to enter more(y/n)\n>>";
            cin >> ans;
        } while (ans == 'y');
    }

    void r_push(int k)
    {
        node *n = new node;
        if (head != NULL)
            head->previous = n;

        n->previous = NULL;
        n->next = head;
        n->bit = k;
        head = n;
    }

private:
    void push(int k)
    {
        if (head == NULL && check(k))
        {
            node *n = new node;
            n->next = NULL;
            n->previous = NULL;
            n->bit = k;
            head = n;
        }
        else if (check(k))
        {
            node *n = new node;
            n->next = NULL;
            n->previous = NULL;
            n->bit = k;
            node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = n;
            n->previous = temp;
        }
    }

public:
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            // cout << "SELF:" << temp << endl;
            // cout << "next: " << temp->next << endl;
            // cout << "previous: " << temp->previous << endl;
            // cout << "DATA: " << temp->bit << endl
            //      << endl;
            cout << temp->bit;
            temp = temp->next;
        }
//        cout << "TAIL" << tail << endl;
    }
    void r_display()
    {
        node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->bit;
            temp = temp->previous;
        }
    }
    int count()
    {
        node * temp=head;
        int counter=0;
        while(temp!=NULL)
        {
            counter++;
            temp=temp->next;
        }
        return counter;
    }
    void make8(){
    	int size=count();
    	for(int i=0;i<8-size;i++){
    		r_push(0);
    	}
    }
    Binary _1comp()
    {
        Binary b;
        node *temp = head;
        while (temp != NULL)
        {
            b.push(!temp->bit);
            temp = temp->next;
        }
        return b;
    }
    Binary _2comp()
    {
    	Binary b;
    	node *temp=tail;
    	bool flag=false;
    	while(temp!=NULL)
    	{
    		if(!flag && temp->bit==1)
    			flag=true;
    		if(!flag){
    			b.r_push(temp->bit);
    		}
    		else{
    			b.r_push(!temp->bit);
    		}
    		temp=temp->previous;
    	}
    	return b;
    }
};
Binary add(Binary a, Binary b)
{
    Binary m;
    a.make8();
    b.make8();
    int sum, carry = 0;
    node *temp_a = a.tail, *temp_b = b.tail;
    while (temp_a != NULL || temp_b != NULL)
    {
        sum = (temp_a->bit + temp_b->bit + carry) % 2;
        carry = (temp_a->bit + temp_b->bit) / 2;
        m.r_push(sum);

        temp_a = temp_a->previous;
        temp_b = temp_b->previous;
    }
    return m;
}
int main()
{
    Binary a, b, sum;
    a.push();
    b=a._2comp();
    // comp = b._1comp();
    // comp.display();
//    a.make8();
    b.display();

    // TODO make a menu
}
