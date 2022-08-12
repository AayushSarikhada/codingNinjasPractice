#include<iostream>
#include "../TreeNode.h"

int getSum(TreeNode<int>* root){
    int tempSum = root->data;
    for(int i=0;i<root->children.size();i++){
        tempSum += root->children[i]->data;
    }
    return tempSum;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    if(root->children.size() == 0) return root;
    
    TreeNode<int>* max = root;
    int tempSum = getSum(root);
    
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* smallNode = maxSumNode(root->children[i]);
        int tempSum2 = getSum(smallNode);
        if(tempSum < tempSum2) max = smallNode;
    }
    
    return max;
}