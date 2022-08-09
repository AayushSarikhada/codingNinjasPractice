#include<vector>
template <typename T>
class TreeNode{
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data = data;
        this->children = NULL;
    }

}