#include<vector>
using namespace std;
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<int>*> children;

    TreeNode(T data=0){
        this->data = data;
        
    }

};