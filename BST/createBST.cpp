#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
    public:

    int data;
    TreeNode * left;
    TreeNode* right;

    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;

    }
};
void printLevelWise(TreeNode* root){
    cout<<root->data<<":";
    queue<TreeNode*> pendingNodes;

    if(root->left != NULL){
        cout<<"L:"<<root->left->data<<",";
        pendingNodes.push(root->left);
    }
    if(root->right != NULL){
        cout<<"R:"<<root->right->data;
        pendingNodes.push(root->right);
    }
    cout<<endl;

    while(pendingNodes.size() != 0){
        TreeNode* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        if(front->left != NULL){
            cout<<"L:"<<front->left->data<<",";
            pendingNodes.push(front->left);
        }
        if(front->left == NULL){
            cout<<"L:"<<-1<<",";
        }

        if(front->right != NULL){
            cout<<"R:"<<front->right->data;
            pendingNodes.push(front->right);
        }
        if(front->right == NULL){
            cout<<"R:"<<-1;
        }
        cout<<endl;

    }
}

TreeNode* insertInBst(TreeNode* root , int data){
    if(root == NULL){
        root = new TreeNode(data);
        return root;
    }

    if(data > root->data){
        //insert in right part
        root->right = insertInBst(root->right ,data);
    }
    else{
        root->left = insertInBst(root->left , data);
    }
    return root;
}

void takeInput(TreeNode * &root){
    int data;
    cin>> data;

    while(data != -1){
        root = insertInBst(root , data);
        cin>>data;
    }
}

int main(){
    TreeNode* root = NULL;
    cout<<"enter values of BSt"<<endl;
    takeInput(root);
    cout<<"printing tree levelwise"<<endl;
    printLevelWise(root);
}