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

void printNodesAtKDepth(TreeNode<int>* root,int k){
    if(root==NULL) return;
    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    for(int i=0;i<root->children.size();i++){
        printNodesAtKDepth(root->children[i],k-1);
    }


}

void preorder(TreeNode<int>* root){
    if(root==NULL) return;
    cout<<root->data<<" ";

    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int>* root){
    if(root == NULL) return;

    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
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


//count number of nodes
int countNodes(TreeNode<int>* root){
    if(root->children.size() == 0) return 1;
    
    int sum =0;

    for(int i=0;i<root->children.size();i++){
        sum += countNodes(root->children[i]);    
    }

    return 1+sum;

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



int countLeafNodes(TreeNode<int>* root){
    if(root==NULL) return 0;
    if(root->children.size()== 0){
        return 1;
    }

    int leafNodes = 0;
    for(int i=0;i<root->children.size();i++){
        leafNodes += countLeafNodes(root->children[i]);
    }
    return leafNodes;
}

void deleteTree(TreeNode<int>* root){
    for(int i=0;i<root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}

//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

/*
note: inorder traversal is only available in binary trees
*/
int main(){
    TreeNode<int>* root;
    root = takeInputByLevels();
    
   
    // printTree(root);
    cout<<"num of nodes:"<<countNodes(root)<<endl;
    // cout<<"nodes at depth 3 : ";
    // printNodesAtKDepth(root,3);
    cout<<endl;

    cout<<"num of leaf Nodes: "<<countLeafNodes(root)<<endl;
    cout<<"preorder : ";
    preorder(root);
    cout<<endl;

    cout<<"postorder : ";
    postorder(root);
    cout<<endl;

    //direct call delete on root because it will auto call destructor of root
    //you wont need deleteNode Function but we can still use that

    //deleteTree(root);
    delete root;
    return 0;
}