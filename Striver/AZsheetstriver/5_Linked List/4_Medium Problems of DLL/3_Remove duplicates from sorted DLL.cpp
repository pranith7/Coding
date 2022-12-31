#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};

Node *newNode(int data){
    Node *temp=new Node(data);    
    return temp;
}

void displayList(Node *head){
    //Head to Tail
    while(head->next){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;    
}

int getLength(Node * head){
    Node *temp=head;
    int count=0;
    while(temp->next!=head){
        count++;
        temp=temp->next;
    }
    return count+1;
}




bool verify(Node* head){
    int fl=0;
    int bl=0;
    
    Node *temp=head;
    
    while(temp->next){
        temp=temp->next;
        fl++;
    }
    
    while(temp->prev){
        temp=temp->prev;
        bl++;
    }
    
    return fl==bl;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/

class Solution
{   
public:
    
    void deleteNode(struct Node **head_ref, struct Node *del)
    {
        /* base case */
        if (*head_ref == NULL || del == NULL)
            return;

        /* If node to be deleted is head node */
        if (*head_ref == del)
            *head_ref = del->next;

        /* Change next only if node to be deleted
            is NOT the last node */
        if (del->next != NULL)
            del->next->prev = del->prev;

        /* Change prev only if node to be deleted
           is NOT the first node */
        if (del->prev != NULL)
            del->prev->next = del->next;

        /* Finally, free the memory occupied by del*/
        free(del);
    }

    /* function to remove duplicates from a
       sorted doubly linked list */
    void removeDuplicates(struct Node **head_ref)
    {
        /* if list is empty */
        if ((*head_ref) == NULL)
            return;

        struct Node *current = *head_ref;
        struct Node *next;

        /* traverse the list till the last node */
        while (current->next != NULL)
        {

            /* Compare current node with next node */
            if (current->data == current->next->data)

                /* delete the node pointed to by
                  'current->next' */
                deleteNode(head_ref, current->next);

            /* else simply move to the next node */
            else
                current = current->next;
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL, *tail=NULL;
        int x;
	    cin>>x;
	    head = newNode(x);
	    tail = head;
	    
	    for(int i=0;i<n - 1;i++)
	    {
	        cin>>x;
	        Node* temp=newNode(x);
	        tail->next=temp;
	        temp->prev= tail;
	        tail = temp;
	    }
	    Solution obj;
	    obj.removeDuplicates(&head);
	    
	    
	    if(verify(head))
	    displayList(head);
	    else
	    cout<<"Your pointers are not correctly connected";
 
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends