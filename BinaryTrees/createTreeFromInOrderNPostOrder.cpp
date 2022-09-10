#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;


BinaryTreeNode<int>* helper(int* postorder,int postStart,int postEnd,int* inorder,int inStart,int inEnd){
	if(postStart > postEnd || inStart>inEnd){
        return NULL;
    }
	
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(postorder[postEnd]);

    int rootIndex=0;
    for(int i=inStart;i<=inEnd;i++){
        if(inorder[i] == root->data){
            rootIndex = i;
            break;
        }
    }
    root->right = helper(postorder,postStart+rootIndex-inStart,postEnd-1,inorder,rootIndex+1,inEnd);
    root->left = helper(postorder,postStart,postStart+rootIndex-inStart-1,inorder,inStart,rootIndex-1);
    

    return root;
    
}
BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return helper(postorder,0,postLength-1,inorder,0,inLength-1);
    
}

int main(){

    BinaryTreeNode<int>* root  = NULL;
    int pre[] = {5,6,2,3,9,10};
    int in[] = {2,6,3,9,5,10};
    root = buildTree(pre,6,in,6);

    return 0;
}