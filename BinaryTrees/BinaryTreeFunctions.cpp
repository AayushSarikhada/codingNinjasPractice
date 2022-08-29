#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

void printTreeLevelWise(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*> pending_nodes;

    pending_nodes.push(root);
    while(!pending_nodes.empty()){
        BinaryTreeNode<int>* curr = pending_nodes.front();
        pending_nodes.pop();
        cout<<curr->data<<": ";

        if(curr->left){
            cout<<"L-"<<curr->left->data;
            pending_nodes.push(curr->left);
        }
        if(curr->right){
            cout<<"R-"<<curr->right->data;
            pending_nodes.push(curr->right);
        }
        cout<<endl;
    }

}
void printTree(BinaryTreeNode<int>* root){
    if(root == NULL) return;

    cout<<root->data<<":";
    if(root->left) cout<<" L-"<<root->left->data;

    if(root->right) cout<<" R-"<<root->right->data;
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}


BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"enter root data: "<<endl;
    cin>>rootData;

    if(rootData == -1) return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pending_nodes;
    pending_nodes.push(root);
    while(!pending_nodes.empty()){
        BinaryTreeNode<int>* front = pending_nodes.front();
        pending_nodes.pop();

        cout<<"enter left child of "<<front->data<<endl;
        int left;
        cin>>left;
        if(left != -1){
            front->left = new BinaryTreeNode<int>(left);
            pending_nodes.push(front->left);
        }

        cout<<"enter right child of "<<front->data<<endl;
        int right;
        cin>>right;
        if(right != -1){
            front->right = new BinaryTreeNode<int>(right);
            pending_nodes.push(front->right);
        }
    }
    return root;
}

int countNodes(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;

    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return (1+left+right);
}

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"enter data: (-1 if data)"<<endl;
    cin>>rootData;
    if(rootData == -1)return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = takeInput();
    root->right = takeInput();
    return root;
}

int height(BinaryTreeNode<int>* root){
    if(root==NULL) return 0;

    return max(height(root->left),height(root->right))+1;
}

//10 20 30 40 50 60 -1 -1 -1 -1 -1 -1
int main(){

    BinaryTreeNode<int>* root = takeInputLevelWise();

    printTreeLevelWise(root);

    cout<<countNodes(root);
    
    delete root;
    return 0;
}

