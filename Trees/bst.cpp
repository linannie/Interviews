#include <iostream>

using namespace std;

class Node{
  private:
    int data;
    Node* right;
    Node* left;
  public: 
    Node();
    ~Node();
    Node* newNode(int data);
    Node* insert(Node* root, int data);

};

Node::Node(){
  data = 0;
  right = NULL;
  left = NULL;
}

Node::~Node(){

}

Node* Node::newNode(int data){
  Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node* Node::insert(Node* root, int data){
  if(root == NULL){                           // if there's no root
    Node* node = newNode(data);               // create a new node!
    return node;
  }
  else{
    if (data < root->data){                   // if the data is less than root data, go left
      root->left = newNode(data); 
    }
    else{
      root->right = newNode(data);            // if the data is more than root data, go right
    }

  } 
  return root;
}


int main(){
  
  return 0;
}
