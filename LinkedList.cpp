#include <iostream>
using namespace std;

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
  LinkedList(){
    head = NULL;
  }

  // add to the end of a Linked List
  void addEnd(int data){
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

  // add to the head of the LL
  void addFront(int data){                   
    Node* newNode = new Node();                       // ALWAYS create a new node
    newNode->data = data;                             // set the data
    if(head != NULL){                                 // if LL is not empty
      newNode->next = head;                           // set the new node as the new HEAD
    }
    head = newNode;                                   // the new node has to be the head now
  }

  // insert at a specific position in a LL
  void addPos(int data, int position){
    // let's say the list is NOT empty

    Node* newNode = new Node();                       // ALWAYS create a new node
    newNode->data = data;                             // set the damn data
    temp = head;                                      // use temp to traverse the LL
    if(!position){                                    // inserting at HEAD
      newNode->next = head;                           // original head becomes the second element
      head = newNode;                                 // new head is the new node
    }
    else{                                             // inserting ANYWHERE ELSE
      for(int i = 0; i < position - 1; i++){          // loop to traverse  
        temp = temp->next;                            // temp goes down the list based off iterations
      }
      newNode->next = temp->next;                     // new node points to the next one
      temp->next = newNode;                           // the original temp's next points to the new node
    }

  }

  // reverse the Linked List
  void reverse(Node* head){
    while(head != NULL){
      head->next->next = head;
      head = head->next;
    }        
  }
    ////////////////// NOT DONE //////////


  // delete a node at a position
  void delNode(int position){
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
  void print(){
    while(head != NULL){                              // when the list isn't over
      cout << head->data << endl;                     // print the data        
      head = head->next;                              // moves onto next pointer to access data
    }
  }

  // print all elements of LL in REVERSE
  void revPrint(Node* head){
    if(head != NULL){                                 // condition in order to traverse down the list
      revPrint(head->next);                           // recursive call to go down the list
      cout << head->data << endl;                     // once the fn call ends, it will print out
    }
  }
  
};

int main(){
  LinkedList newList;
  

  newList.addEnd(1);
  newList.addEnd(2);
  newList.addFront(0);
  newList.addEnd(3);
  newList.addEnd(4);
  newList.addEnd(5);
  //newList.addPos(100,5);
  /*newList.addEnd(3);
  newList.addEnd(5);

  newList.addFront(20);
  
  */
  //newList.addPos(8,0 );
  //newList.print();

 // newList.revPrint(newList.head);
 
  return 0;
}

