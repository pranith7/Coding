#include<bits/stdc++.h>
using namespace std;

class node{
    private:
    protected:
    public:
    int x;
    node *nxt;
};

node *head;
node *newnode;
void creation()
{
    node *temp;
    head = NULL;
    int choice=1;
    while (choice != 0)
    {
        newnode = new node;
        cout << "Enter the new node ::";
        cin >> newnode->x;
        newnode->nxt = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->nxt = newnode;
            temp = newnode;
        }
        cout << "Enter (1/0) to continue ::";
        cin >> choice;
    }
    
}

void insertatbeg()
{
    newnode = new node;
    cout<<"Enter the node to be added at beg"<<endl;
    cin>>newnode->x;
    newnode->nxt = head;
    head = newnode;
}

void insertatend()
{
    node *tx;
    tx = head;
    // node *newnode;
    newnode = new node;
    cout<<"enter node to be at end"<<endl;
    cin>>newnode->x;
    newnode->nxt = 0;
    while(tx->nxt!=0)
    {
        tx = tx->nxt;
    } 
    tx->nxt = newnode;
}


void insertatlocation()
{
    node *temp = head;
    newnode = new node;
    int pos, i = 1;
    cout << "Enter the position to be inserted ";
    cin >> pos;
    if (pos<0)
    {
        cout << "Invalid Position";
    }
    else
    {
        while (i < pos)
        {
            temp = temp->nxt;
            i++;
        }
        cout << "Enter to be inserted at position ::";
        cin >> newnode->x;
        newnode->nxt = temp->nxt;
        temp->nxt = newnode;
    }
}
delfrombeg()
{
    head = head->nxt;//one line code can work
}

delfromend(){
    node *prev,*temp;
    temp = head;
    while(temp->nxt != 0){
        prev = temp;
        temp = temp->nxt;
    }
    /*
     another way to do it wihtout using 
     prev pointer is{
         while (temp->nxt->nxt!=0){
             temp = temp->nxt;
         }
         if()
         {

         }
         else{
             temp->nxt = 0;
         }
    */
    if(temp == head) {
        head = 0;
    }
    else
    {
        prev->nxt = 0;
    }
    free(temp);
}

delfrompos()
{
    int pos,i=1;
    node *nxtnode,*temp = head;
    cout<<"Enter position"<<endl;         
    cin>>pos;
    while(i<pos-1){
        temp = temp->nxt;
        i++;
    }
    nxtnode = temp->nxt;
    temp->nxt = nxtnode->nxt;
    free(nxtnode);
}
void display()
{
    node *t;
    t = head;
    while(t->nxt!=0)
    {
        cout<<t->x<<" ";
        t = t->nxt;
    }
    cout<<t->x;
}
int main(){

    creation();
    insertatbeg();
    insertatend();
    display();
    cout<<endl;
    insertatlocation();
    display();
    return 0;
}


/*
    1. -->is Done 
    2. Concept of it is 
       {
           Requirements:-
                1. Have a linkedlist with me
                2. Having number k

           Approach:-
           {
                **Traversing function **
                {
                    if(temp->nxt == k) 
                    {   
                        flag = 1
                        // break;
                    }
                } 
                if(flag) cout<<"Yes"<<endl;
                else cout<<"NO"<<endl;
            } 

       }
    3. print(Nth node) --> Basic Traversing thing
    4. mostly uses the concept of --> 2 instead of flag there is going to be a
       counter variable which is going to count the number of specific values in the 
       above created linkedlist.
    5. concept{
        2->variables 
           max = INT_MIN;
           min = INT_MAX;
           node *temp =  head;
           **Traversing Function*{
               if(temp->x < min ) min = temp->x;
               if(temp->x > max)  max = temp->x; 
           }
           cout<<"maximum element in the linkedlist is"<<max<<endl;
           cout<<"minimum element in the linkedlist is"<<min<<endl;
    }  
*/



//vscode version
