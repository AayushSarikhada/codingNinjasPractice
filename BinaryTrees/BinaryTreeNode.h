template <typename T>
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        BinaryTreeNode(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }

        //delete NULL is ignored
        ~BinaryTreeNode(){
            delete left;
            delete right;
        }
};