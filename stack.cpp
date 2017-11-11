#include <iostream>
using namespace std;

class Stack{
  private:
    int* stack;
    int head;
    int length;

  public:
    Stack(int size);  // stack constructor
    ~Stack();         // destructor
    int push(int data);
    int pop();
    void printStack();
};

Stack::Stack(int size){
  head = -1;                         // head is nothing
  length = size;                    
  stack = new int[length];          // stack array is dynamic

}

Stack::~Stack(){
  delete [] stack;

}

int Stack::push(int data){
  if (head == length){
    cout << "Stack is full." << endl;
    return 0;
  }
  head++;
  stack[head] = data;
  return 0;

}

int Stack::pop(){
  if (head == 0){
    cout <<  "Empty Stack" << endl;
    return 0;
  }
  int value = stack[head];
  head--;
  return value;
}

void Stack::printStack(){
  for(int i = 0; i <= head; i++){      // check if < or <=
    cout << stack[i] << " ";
  }
  cout << endl;
}

int main(){

  Stack myStack(5);

  myStack.push(1);
  myStack.push(4);
  myStack.push(8);

  myStack.printStack();

  int popped = myStack.pop();
  cout << "I popped " << popped << endl;

  myStack.printStack();

  return 0;
}
