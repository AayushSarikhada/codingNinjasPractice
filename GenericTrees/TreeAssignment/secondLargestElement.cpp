#include<iostream>
#include"../TreeNode.h"
using namespace std;

TreeNode<int>* getLargestElementNode(TreeNode<int>* root){
    if(root->children.size()==0) return root;
    
    TreeNode<int>* current = NULL;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* temp = getLargestElementNode(root->children[i]);
        if(current == NULL) current = temp;
        else{
            if(current->data < temp->data) current = temp;
        }
    }
    if(root->data > current->data) current = root;
    return current;
}

TreeNode<int>* helper(TreeNode<int>* root,int target){
    
    TreeNode<int>* current = NULL;
    
    // if(root->children.size()==0){
    //     if(root->data < target){
    //         current = root;
    //     }
    //     return current;
    // }
    
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* temp = helper(root->children[i],target);
        if(temp == NULL) continue;
        if(current == NULL){
            current = temp;
        }else{
            if(current->data < temp->data){
                current = temp;
            }
        }
    }
    
    if(current != NULL){
    	if(current->data < root->data && root->data < target){
            current = root;
        }
    }else{
        if(root->data < target)
            current = root;
    }
    return current;
    
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here  
    if(root==NULL) return root;
    if(root->children.size()==0) return NULL;
    TreeNode<int>* largestNode = getLargestElementNode(root);
   
    
    return helper(root,largestNode->data);
}