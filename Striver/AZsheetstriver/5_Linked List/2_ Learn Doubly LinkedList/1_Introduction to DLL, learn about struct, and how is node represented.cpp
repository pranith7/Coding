#include <bits/stdc++.h>
using namespace std;

class node
{
    // private:
    // protected:
public:
    int x;
    node *nxt;
    node *prv;
};

node *head;
node *newnode;
node *tail;
void creation()
{
    head = NULL;
    int choice = 1;
    while (choice != 0)
    {
        newnode = new node;
        cout << "Enter the new node ::";
        cin >> newnode->x;
        newnode->prv = NULL;
        newnode->nxt = NULL;
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->nxt = newnode;
            newnode->prv = tail;
            tail = newnode;
        }
        cout << "Enter (1/0) to continue ::";
        cin >> choice;
    }
}
void insertatbeg()
{
    newnode = new node;
    cout << "Enter data to insert at beg ::";
    cin >> newnode->x;
    newnode->nxt = 0;
    newnode->prv = 0;
    if (head == 0)
    {
        head = tail = newnode;
    }
    else
    {
        head->prv = newnode;
        newnode->nxt = head;
        head = newnode;
    }
}
void insertatend()
{
    newnode = new node;
    cout << "Enter data to insert at end ::";
    cin >> newnode->x;
    newnode->nxt = 0;
    newnode->prv = 0;
    if (head == 0)
    {
        head = tail = newnode;
    }
    else
    {
        tail->nxt = newnode;
        newnode->prv = tail;
        tail = newnode;
    }
}
int getlength()
{
    int cnt=0;
    node *t;
    t = head;
    while(t->nxt!=0)
    {
        cnt++;
        t = t->nxt;
    }
    return cnt+1;
}
void insertatpos()
{
    int pos,l;
    cout << "Enter Position to be inserted at position ::";
    cin >> pos;
    l = getlength();
    if (pos < 1 && l+1)
    {
        cout << "Invalid Position ::";
    }
    else if (pos==1)
    {
        insertatbeg();
    }
    else if(pos==l+1)
    {
        insertatend();
    }
    else
    {
        int i = 1;
        newnode = new node;
        node *t = head;
        cout << "Enter data to be inserted at position::";
        cin >> newnode->x;
        while (i < pos - 1)
        {
            t = t->nxt;
            i++;
        }
     
    }
}

void insertatafterpos()
{
    int pos;
    cout << "Enter Position to be inserted at after position ::";
    cin >> pos;
    if (pos < 1)
    {
        cout << "Invalid Position ::";
    }
    else
    {
        int i = 1;
        newnode = new node;
        node *t = head;
        cout << "Enter data to be inserted at after position ::";
        cin >> newnode->x;
        while (i < pos)
        {
            t = t->nxt;
            i++;
        }
        newnode->prv = t;//1->2->3->4
        newnode->nxt = t->nxt;
        t->nxt->prv = newnode;
        t->nxt = newnode;
    }
}

void deletionfrombeg()
{
    node *t2 = head;
    if (head == 0)
    {
        cout << "Empty linked list";
    }
    else
    {
        head = head->nxt;
        head->prv = 0;
        free(t2);
    }
}

void deletionfromend()
{
    node *t1 = tail;
    if (tail == 0)
    {
        cout << "Empty linkedlist";
    }
    else
    {
        tail->prv->nxt = 0; //delete this line
        tail = tail->prv;   //Insert after thi sline this >> tail = tail->nxt = 0;
        free(t1);           //same result;
    }
}
void deleteatpos()
{
    int pos, i = 1;
    node *t3 = head;
    cout << "Enter data to be deleted at position::";
    cin >> pos;
    while (i < pos)
    {
        t3 = t3->nxt;
        i++;
    }
    t3->prv->nxt = t3->nxt;
    t3->nxt->prv = t3->prv;
    free(t3);
}
int display()
{
    int max, min;
    node *ptr;
    cout << "Let's start the list traversal!" << endl;
    ptr = head;
    max = INT_MIN;
    min = INT_MAX;
    while (ptr != NULL)//1->2->3->4
    {
        cout << ptr->x << '\n';
        if (max < ptr->x)
            max = ptr->x;
        if (min > ptr->x)
            min = ptr->x;
        ptr = ptr->nxt;
        // count++;
    }
    // cout << "Length of linked list ::" << count << endl;
    cout << "MAximum element in the linkedlist is " << max << endl;
    cout << "Minimum element in thr linkedlist is " << min << endl;
    return 0;
}
int search(int tar)
{
    int count = 1;
    node *ptr;
    cout << "Let's start the list traversal!" << endl;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->x == tar)
        {
            cout << "YES" << endl;
            cout << "Element is present at"
                 << " " << count << " "
                 << "this position";
        }
        ptr = ptr->nxt;
        count++;
    }
    return 0;
}
int giventhnode(int ele)
{
    int count = 0;
    node *ptr;
    cout << "Let's start the list traversal!" << endl;
    ptr = head;
    while (ptr != NULL)
    {
        if (count == ele)
        {
            cout << ptr->x;
        }
        ptr = ptr->nxt;
        count++;
    }
    return 0;
}
int main()
{
    creation();
    insertatbeg();
    insertatend();
    insertatpos();
    insertatafterpos();
    // display();
    // deletionfrombeg();
    // deletionfromend();
    // display();
    // deleteatpos();
    display();
    // search(tar);
    // giventhnode(ele);
    //lengthll();

    return 0;
}
