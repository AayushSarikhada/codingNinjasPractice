#include <iostream>
#include "../TreeNode.h"

bool isPresent(TreeNode<int>* root, int x) {
    // Write your code here
    if(root==NULL ) return false;
    
    if(root->data == x){
        return true;
    }
    
    bool small = false;
    for(int i=0;i<root->children.size();i++){
    	small = isPresent(root->children[i],x);
        if(small) return small;
    }
    return small;
    
}