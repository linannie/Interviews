#include <iostream>
using namespace std;

// This file will contain additional LL problems


class Node{
  public:
  Node* next;
  int data;
  Node(){
    next = NULL;
  }
};

class LinkedList{
  public:
  Node *head;
  Node* temp;
  void addEnd(int data);
  void addFront(int data);
  void addPos(int data, int position);
  void delNode(int position);
  void print();
  
  LinkedList(){
    head = NULL;
  }
};

// add to the end of a Linked List
void LinkedList::addEnd(int data){
  if(head == NULL){                                 // if the LL is empty   
    Node* newNode = new Node();                     // create a new node
    newNode->data = data;                           // set the data
    head = newNode;                                 // set head as the new Node
    temp = head;                                    // create a temp so you can keep your head
  }
  else if(temp->next == NULL){                      // if you're at the end of the LL
    Node* newNode = new Node();                     // create a new node
    newNode->data = data;                           // set the data
    temp->next = newNode;                           // set the end to the new Node
  }  
  else{                                             // while you're traversing the list  
    temp = temp->next;                              // temp goes down the list
    addEnd(data);                                   // recursively call to move down the list    
  }
}

// delete a node at a position
void LinkedList::delNode(int position){
  // list is NOT empty

  temp = head;                                      // use temp to traverse the LL
  if(!position){                                    // if you want to delete the 0th position
    head = temp->next;                              // set head to the 1st position
  }
  else{                                             // deleting from all OTHER positions
    for(int i = 0; i < position - 1; i++){          // loop to traverse (only go in if pos >= 2
      temp = temp->next;                            // temp goes down the list    
    }
    temp->next = temp->next->next;                  // temp's next pointer ignores the next elem (deletes)
                                                     // bc it points to the one after it
  }
}

// print out all elements in LL
void LinkedList::print(){
  while(head != NULL){                              // when the list isn't over
    cout << head->data << endl;                     // print the data        
    head = head->next;                              // moves onto next pointer to access data
  }
}


/* PROBLEMS START HERE */


// Remove duplicates from an unsorted linked list


int main(){
  LinkedList newList;
  

  newList.addEnd(1);
  newList.addEnd(2);
  newList.addFront(0);
  newList.addEnd(3);
  newList.addEnd(4);
  newList.addEnd(5);
  //newList.print();

 
  return 0;
}

