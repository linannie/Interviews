#include <iostream>

using namespace std;

class Queue{
  private:
    int* queue;
    int head;
    int tail;
    int length;
  public:
    Queue(int size);          // q constructor
    ~Queue();                 // destructor
    int enqueue(int data);
    int dequeue();
    void printQ();
};

Queue::Queue(int size){
  head = -1;
  tail = 0;
  length = size;
  queue = new int[length];
  
}

Queue::~Queue(){

  delete [] queue;
}

int Queue::enqueue(int data){
  if(head == length){
    cout << "Queue is full" << endl;
    return 0;
  }
  head++;
  queue[head] = data;
  return 0;
}

int Queue::dequeue(){
  if(tail == length){
    cout << "Empty queue" << endl;
    return 0;
  }
  int value = queue[tail];
  tail++;
  return value; 

}

void Queue::printQ(){
  for(int i = tail; i <= head; i++){
    cout << queue[i] << " ";
  }
  cout << endl;

}

int main(){
  Queue myQueue(5);
  
  myQueue.enqueue(1);
  myQueue.enqueue(5);
  myQueue.enqueue(17);
 
  myQueue.printQ();
  int value = myQueue.dequeue();
  
  cout << "Just dequeued " << value << endl;
  myQueue.printQ();

  return 0;
}



