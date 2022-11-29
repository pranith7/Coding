/*Delete Last Node of Linked List*/
#include <bits/stdc++.h>

using namespace std;

class ListNode {
  public:
    int val;
  ListNode * next;
  ListNode(int x) {
    val = x;
    next = nullptr;
  }
};

ListNode * head, * tail; // head and tail of the LinkedList

void PrintList() // Function to print the LinkedList
{
  ListNode * curr = head;
  for (; curr != nullptr; curr = curr -> next)
    cout << curr -> val << "-->";
  cout << "null" << endl;
}

void InsertatLast(int value) // Function for creating a LinkedList
{

  ListNode * newnode = new ListNode(value);
  if (head == nullptr)
    head = newnode, tail = newnode;
  else
    tail = tail -> next = newnode;
}

void DeleteLast() {
  if (head == nullptr)
    cout << "There are no nodes to delete in LinkedList" << endl;

  // If there is single node, delete that and make head point to null
  if (head -> next == nullptr) {
    delete head;
    head = nullptr;
  } else {

    // step1: Finding First and Second Last Node in LinkedList

    ListNode * curr = head, * prev = nullptr;
    while (curr -> next != nullptr) {
      prev = curr;
      curr = curr -> next;
    }

    // Step2 : Pointing prev->next to nullptr

    prev -> next = nullptr;

    // Step3 :Deleting the LastNode

    delete curr;
  }
}

int main() {
  InsertatLast(10);
  InsertatLast(20);
  InsertatLast(30);
  InsertatLast(40);
  cout << "LinkedList before Deleting Last Node : " << endl;
  PrintList();
  DeleteLast();
  cout << "LinkedList after Deleting Lastt Node : " << endl;
  PrintList();
  return 0;
}