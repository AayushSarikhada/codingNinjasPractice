#include<iostream>
#include"../TreeNode.h"
using namespace std;

void helper(TreeNode<int>* root,int depth){
    if(root==NULL) return;
    
    TreeNode<int>* temp = root;
    for(int i=0;i<temp->children.size();i++){
       	helper(root->children[i],depth+1);
    }
    
    root->data = depth;
    
}
void replaceWithDepthValue(TreeNode<int>* root) {
    // Write your code here
    helper(root,0);
}