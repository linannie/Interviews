#include <iostream>

using namespace std;

class Node{
  public:
    int data;
    Node* right;
    Node* left;
  //public: 
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
    return newNode(data);               // create a new node!
  }
  if (data < root->data){                   // if the data is less than root data, go left
    root->left = insert(root->left, data); 
  }
  if (data > root->data){
    root->right = insert(root->right, data);  // if the data is more than root data, go right
  }

   
  return root;
}

/////////// TRAVERSALS ////////////////
void preorder(Node* node){
  if(node != NULL){
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
  }
}

void inorder(Node* node){                   // Left, data, Right
  if(node != NULL){
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
  }
}

void postorder(Node* node){
  if(node != NULL){
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
  }
}

///////////// SEARCHES ////////////
void DFS(Node *root, int value){


}

void BFS(Node *root, int value){


}


int main(){
  Node* root = root->newNode(50);                           
  root->insert(root, 20);                        
  root->insert(root, 69);
  root->insert(root, 70);
  root->insert(root, 13);
  root->insert(root, 23);
  root->insert(root, 56);
  

  cout << "INORDER: ";
  inorder(root);
  cout << endl;

  cout << "PREORDER: ";
  preorder(root);
  cout << endl;
 
  cout << "POSTORDER: ";
  postorder(root);
  cout << endl;
  return 0;
}
