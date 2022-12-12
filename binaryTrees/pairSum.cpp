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
pair<int,int> pairSum(BTNode<int>* root , int x){
    if(root == NULL){
        pair<int,int> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }

    pair<int,int> leftAns = pairSum(root->left,x);
    pair<int,int> rightAns = pairSum(root->right,x);
    int leftdata = leftAns.first;
    int rightdata = rightAns.first;

    if(root->data + leftdata == x){
        pair<int,int> p;
        p.first = root->data;
        p.second = leftdata;
        return p;
    }
    else if(root->data + rightdata == x){
        pair<int,int> p;
        p.first = root->data;
        p.second = rightdata;
        return p;
    }
}

int main(){
    
    BTNode<int> * root = takeInputLevelWise();
    int x;
    cout<<"enter target";
    cin>>x;
    pair<int,int> p = pairSum(root,x);
    cout<<p.first<<" "<<p.second;
    // printLevelWise(root);

}