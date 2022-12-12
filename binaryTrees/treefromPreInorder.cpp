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

void printLevelWise(BTNode<int>* root){
    cout<<root->data<<":";
    queue<BTNode<int>*> pendingNodes;

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
        BTNode<int>* front = pendingNodes.front();
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
BTNode<int>* construct(int *pre, int *in ,int preS ,int preE, int inS, int inE){
    if(inS > inE) return NULL;
    
    int rootData = pre[preS];
    
    int lpreS = preS +  1;
    int linS = inS;

    int rootIndex = -1;
    
    for(int i = inS;i<=inE;i++){
        if(in[i] == rootData){
            rootIndex = i;
            break;
        }
    }
    int linE = rootIndex -1;
    int lpreE = linE + lpreS - linS;

    int rpreS = lpreE +1;
    int rpreE = preE;
    int rinS = rootIndex+1;
    int rinE = inE;
    BTNode<int>* rootNode = new BTNode<int>(rootData);
    
    rootNode ->left = construct(pre,in,lpreS,lpreE, linS ,linE);

    rootNode->right= construct(pre,in,rpreS,rpreE, rinS ,rinE);
    
    return rootNode;

}

BTNode<int>* constructTree(int n, int pre[] , int in[] ){
    return construct(pre,in,0,n-1,0, n-1);
}

void inorder(BTNode<int>* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

 
int main(){
    int n;
    cin>>n;
    int pre[n];
    for(int i=0; i<n;i++){
        cin>>pre[i];
    }
    int in[n];
    for(int i=0; i<n;i++){
        cin>>in[i];
    }

    BTNode<int>* root = constructTree(n,pre,in);
    printLevelWise(root);
    cout<<endl;
    inorder(root);

}