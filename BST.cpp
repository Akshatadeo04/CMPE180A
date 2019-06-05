#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* insertion(Node *root, int x){
    if(root == NULL){
        Node *newNode = new Node;
        newNode->data = x;
        newNode->left = newNode->right = NULL;
        root = newNode;
        return root;
    }
    else if(x <= root->data){
        root->left = insertion(root->left, x);
    }
    else{
        root->right = insertion(root->right, x);
    }
}

void print(Node* root){
    //preorder
    if(root == NULL) return;
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

bool searching(Node *root, int x){
    if(root == NULL) return 0;
    else if (x == root->data) return 1;
    else if(x < root->data) searching(root->left, x);
    else searching(root->right,x);
}

int findHeight(Node *root){
    if(root == NULL) return -1;
    return (max(findHeight(root->left),findHeight(root->right)+1));
}

void bfs(Node *root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *current = q.front();
        cout << current->data << " ";
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
        q.pop();
    }
}

Node* findMin(Node* root){
    if(root == NULL) return root;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* deleting(Node *root, int x){
    if(root == NULL) return root;
    else if(x< root->data) root->left = deleting(root->left, x);
    else if(x> root->data) root->right = deleting(root->right, x);
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            Node *current = root;
            root = root->right;
            delete current;
            current = NULL;
        }
        else if(root->right == NULL){
            Node *current = root;
            root = root->left;
            delete current;
            current = NULL;
        }
        else{
            Node *current = findMin(root->right);
            root->data = current->data;
            root->right = deleting(root->right, current->data);
        }
    }
    return root;
}

int main()
{
    Node* root = NULL;
    root = insertion(root,15);
    root = insertion(root,10);
    root = insertion(root,20);
    root = insertion(root,25);
    root = insertion(root,8);
	print(root);
	cout << endl << searching(root, 12) << endl;
	cout << findHeight(root) << endl;
	bfs(root);
	deleting(root, 25);
	cout << endl;
	print(root);
    return 0;
}
