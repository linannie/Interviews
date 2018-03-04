#include <iostream>

using namespace std;

class QueueNode{
  int data;
  QueueNode next;
  QueueNode(int data){
    data = data;
  }

};

class Queue{
  QueueNode head;
  QueueNode tail; 
  void add(int item);
  void remove();
  void peek();
  bool isEmpty();
};

void Queue::add(int item){


}

void Queue::remove(){


}

void Queue::peek(){

}

bool Queue::isEmpty(){


}

int main(){

  return 0;
}
