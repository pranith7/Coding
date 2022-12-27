//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:

Node* rev(Node* head){

        if(head==NULL||head->next==NULL){

            return head;

        }

         Node* curr=head;

        Node* prev=NULL;

       Node* nex;

        while(curr!=NULL){

            nex=curr->next;

            curr->next=prev;

            prev=curr;

            curr=nex;

    }

    return prev;

    }

    public:

    Node* addOne(Node *head) 

    {

        // Your Code here

        // return head o

    //f list after adding one

        head=rev(head);

        Node* dummy=new Node(0);

        Node* curr=dummy;

        int carry=0;

        Node* one=new Node(1);

        one=rev(one);

        while(head!=NULL||carry||one!=NULL){

            int sum=0;

            if(head!=NULL){

                sum+=head->data;

                head=head->next;

            }

            if(one!=NULL){

                sum+=one->data;

                one=one->next;

            }

            sum=sum+carry;

            carry=(sum/10);

            curr->next=new Node(sum%10);

            curr=curr->next;

        }

        Node* m=dummy->next;

        m=rev(m);

        return m;

        

       

    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends