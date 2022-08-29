#include <iostream>
#include "../TreeNode.h"

int getLargeNodeCount(TreeNode<int>* root, int x) {
    // Write your code here
    if(root==NULL) return 0;
    
    
    
    int sum = 0;
    for(int i=0;i<root->children.size();i++){
        sum += getLargeNodeCount(root->children[i],x);
    }
    if(root->data > x) return 1+sum;
    return sum;
}