#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;


BinaryTreeNode<int>* helper(int* preorder,int preStart,int preEnd,int* inorder,int inStart,int inEnd){
	if(preStart > preEnd || inStart>inEnd){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[preStart]);

    int rootIndex=0;
    for(int i=inStart;i<=inEnd;i++){
        if(inorder[i] == root->data){
            rootIndex = i;
            break;
        }
    }

    root->left = helper(preorder,preStart+1,preStart+(rootIndex-inStart),inorder,inStart,rootIndex-1);
    root->right = helper(preorder,preStart+(rootIndex-inStart)+1,preEnd,inorder,rootIndex+1,inEnd);

    return root;
    
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    return helper(preorder,0,preLength-1,inorder,0,inLength-1);
    
}

int main(){

    BinaryTreeNode<int>* root  = NULL;
    int pre[] = {5,6,2,3,9,10};
    int in[] = {2,6,3,9,5,10};
    root = buildTree(pre,6,in,6);

    return 0;
}