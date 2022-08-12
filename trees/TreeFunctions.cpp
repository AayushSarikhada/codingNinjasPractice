#include<iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;

//print the tree in a manner that user can understand what is the structure
//of the tree
void printTree(TreeNode<int>* root){

    //edge case (not base case)
    if(root==NULL) return;

    cout<<root->data<<": ";

    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
        
    }
}

TreeNode<int>* takeInputByLevels(){
    TreeNode<int>* root = new TreeNode<int>();
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    cout<<"enter root data: "<<endl;
    cin>>root->data;

    while(!pendingNodes.empty()){
    TreeNode<int>* front = pendingNodes.front();
    pendingNodes.pop();
    cout<<"enter number of children: "<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int childData;
        cout<<"enter "<<i<<"th child of "<<front->data<<endl;
        cin>>childData;
        TreeNode<int>* child = new TreeNode<int>(childData);
        front->children.push_back(child);
        pendingNodes.push(child);
    }
    }
    return root;

}

//printlevelwise

void printLevelWise(TreeNode<int>* root) {
    // Write your code here

   queue<TreeNode<int>*> rem;
   rem.push(root);
   while(!rem.empty()){
    TreeNode<int>* current = rem.front();
    rem.pop();
    cout<<current->data<<":";
    for(int i=0;i<current->children.size();i++){
        rem.push(current->children[i]);
        
    }
       
    int i;
    for(i=0;i<current->children.size()-1;i++){
        cout<<current->children[i]->data<<",";
    }
    if(current->children.size() != 0)
    	cout<<current->children[i]->data<<endl;
   
   }

  
}

//count number of nodes
int countNodes(TreeNode<int>* root){
    if(root->children.size() == 0) return 1;
    
    int sum =0;

    for(int i=0;i<root->children.size();i++){
        sum += countNodes(root->children[i]);    
    }

    return root->data+sum;

}

//take tree input
//v1 complicated way
TreeNode<int>* takeInputV1(TreeNode<int>* root){
    cout<<"enter data:"<<endl;
    cin>>root->data;
    int n;
    cout<<"enter number of children:"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        int da;
        TreeNode<int>* child = new TreeNode<int>();
        root->children.push_back(child);
        takeInputV1(root->children[i]);
    }

    return root;
}

TreeNode<int>* maxNode(TreeNode<int>* root){
    if(root->children.size() == 0){
        return root;
    }

    TreeNode<int>* max = root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* smallMax = maxNode(root->children[i]);
        if(max->data < smallMax->data){
            max = smallMax;
        }
    }

    return max;
}


int getHeight(TreeNode<int>* root){
    if(root==NULL) return 0;

    int max=0;
    for(int i=0;i<root->children.size();i++){
        int smallMax = getHeight(root->children[i]);
        if(max < smallMax) max = smallMax;
    }
    return max+1;
}

int main(){
    TreeNode<int>* root;
    root = takeInputByLevels();
    
   
    printTree(root);

    return 0;
}