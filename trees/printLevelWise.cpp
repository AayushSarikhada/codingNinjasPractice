#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

void printLevelWise(TreeNode<int>* root) {
    // Write your code here

   queue<TreeNode<int>*> rem;
   rem.push(root);
   while(!rem.empty()){
    TreeNode<int>* current = rem.front();
    rem.pop();
    cout<<current->data<<":";
    for(int i=0;i<current->children.size();i++){
        rem.push(current->children[i]);
        
    }
       
    int i;
    for(i=0;i<current->children.size()-1;i++){
        cout<<current->children[i]->data<<",";
    }
    if(current->children.size() != 0)
    	cout<<current->children[i]->data<<endl;
   
   }

  
}

    // if(root == NULL) return;
    
	// queue<TreeNode<int>*> rem;
    // cout<<root->data<<":";
    // int i;
    
    // for(i=0;i<root->children.size()-1;i++){
    //     cout<<root->children[i]->data<<",";
    //     rem.push(root->children[i]);
    // }cout<<root->children[i]->data<<endl;
    // rem.push(root->children[i]);
    
	// while(!rem.empty()){
    //     TreeNode<int>* front = rem.front();
    //     rem.pop();
    //     printLevelWise(front);
    // }


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}