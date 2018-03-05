#include <iostream>
#include <queue>

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
  if(!root){                           // if there's no root
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
  if(node){
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
  }
}

void postorder(Node* node){
  if(node){
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
  }
}

void levelorder(Node* root){
  queue<Node *> q;
  
  if(root)
    q.push(root);
  while(!q.empty()){
    Node* temp = q.front();
    cout << temp->data << " ";
    q.pop();
    if(temp->left)
      q.push(temp->left);
    if(temp->right)
      q.push(temp->right);
  }  

}
///////////// SEARCHES ////////////
void DFS(Node *root, int value){


}

void BFS(Node *root, int value){


}

int height(Node* root){                 // returns the # of longest edges
  int left = 0, right = 0;
  
  if(root->left)                        // if left child exists
    left = 1 + height(root->left);      // traverse down the left side
  if(root->right)
    right = 1 + height(root->right);
  if(left > right)
    return left;
  return right;

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
  
  cout << "LEVELORDER: ";
  levelorder(root);
  cout << endl;

  int ht = 0;
  ht =  height(root);
  cout << "Height of tree is: " << ht << endl;
  return 0;
}
