#include<iostream>
using namespace std;

class List;

class Node{
   
   int data;

public:
    Node(int d):data(d),next(NULL) {}//-->Initialization list  instead of assignment list which is in paranthesis
    Node* next;
    int getData()
    {
        return data;
    }

    ~Node()
    {
        if(next!= NULL) 
        {
            delete next;
        }
        cout<<"data at the deletion"<<data<<endl;
    }
    friend class List;

};

class List
{
    Node* head;
    Node* tail;

    int searchHelper(Node* start,int key)
   {
       if(start == NULL)
       {
           return -1;
       }
       if(start->data == key)
       {
           return 0;
       }

       int subidx = searchHelper(start->next,key);
       if(subidx == -1) return -1;
       return subidx + 1;
   }

    public:
        List():head(NULL),tail(NULL) {}

        Node* begin()
        {
            return head;
        }

        void push_front(int data)
        {
            if(head == NULL)
            {
                Node * n = new Node(data);
                head = tail = n;
            }
            else{
                Node * n = new Node(data);
                n->next = head;
                head = n;
            }
        }

        void push_back(int data)
        {
            if(head == NULL)
            {
                Node * n = new Node(data);
                head = tail = n;
            }
            else
            {
                Node * n = new Node(data);
                tail->next = n;
                tail = n;
            } 
        } 

        void insert(int data, int pos)
        {
            if(pos == 0)
            {
                push_front(data);
                return;
            }
            Node* temp = head;
            for(int jumps=1;jumps<=pos-1;jumps++)
            {
                temp = temp->next;
            }
            Node* n = new Node(data);
            n->next = temp->next;
            temp->next = n;
        } 

        void pop_front()
        {
            Node* temp = head;
            temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }

        int search(int key)
        {
 
		Node * temp = head;
		int idx = 0;
 
		while(temp!=NULL){
			if(temp->data == key){
				return idx;
			}
			idx++;
			temp = temp->next;
		}	
		return -1;
	    }

        int recursiveSearch(int key)
        {
            int idx = searchHelper(head,key);
            return idx;
        }
        ~List()
        {
            if(head!=NULL)
            {
                delete head;
                head = NULL;
            }
        }



};