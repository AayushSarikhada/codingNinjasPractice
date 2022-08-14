#include<iostream>
#include"../TreeNode.h"
using namespace std;

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
   	TreeNode<int>* current = NULL;
	
    if(root->children.size()==0){
        if(root->data > x){
            current = root;
            return current;
        }
        return current;
    }
    
    for(int i=0;i<root->children.size();i++){
        
        TreeNode<int>* small = getNextLargerElement(root->children[i],x);
        if(small == NULL){
            continue;
        }
        
        if(current == NULL) current = small;
    	else{
            if(current->data > small->data){
                current = small;
            }
        }
        
    }
    
    if(current == NULL){
        if(root->data > x){
            current = root;    
        }
        
    }
    else{
        if(current->data > root->data && root->data > x){
            current = root;
        }
    }
    return current;
   	
    
}