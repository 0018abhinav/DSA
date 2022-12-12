#include<iostream>
using namespace std;
#include<queue>

template <typename T>

class BTNode{
    public:
    T data;
    BTNode<T>* left;
    BTNode<T>* right;

    BTNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BTNode(){
        delete left;
        delete right;
    }

};


BTNode<int> * takeInputLevelWise(){
    int rootData;
    cout<<"enter root data"<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BTNode<int> * root = new BTNode<int>(rootData);
    queue<BTNode<int>*> pendingNodes ;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        BTNode<int>* front =  pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cout<<"enter left child data of"<<front->data<<endl;
        cin>>leftChildData;
        if(leftChildData != -1){
            BTNode<int>* child = new BTNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        int rightChildData;
        cout<<"enter right child data of"<<front->data<<endl;
        cin>>rightChildData;
        if(rightChildData != -1){
            BTNode<int>* child = new BTNode<int>(rightChildData);
            front->right= child;
            pendingNodes.push(child);
        }
    }
    return root;

}

int height(BTNode<int>* root){
    if(root == NULL){
        return 0;
    }

    return 1+ max(height(root->left),height(root->right));
}

int main(){
    // BTNode<int> * root = takeInput();
    BTNode<int> * root = takeInputLevelWise();
    int ans = height(root);
    cout<<ans;

}