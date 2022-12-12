#include<bits/stdc++.h>
using namespace std;

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

vector<int> topView(BTNode<int>* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map<int,int> topNodes;
    queue<pair<BTNode<int>*,int>> q;
    q.push({root,0});

    while(!q.empty()){
        pair<BTNode<int>* ,int> temp = q.front();
        q.pop();

        BTNode<int>* frontNode = temp.first;
        int hd = temp.second;

        //if one value is present for hd , then do nothing, else

        if(topNodes.find(hd) == topNodes.end()){
            topNodes[hd] = frontNode->data;
        }

        if(frontNode->left){
            q.push({frontNode->left , hd-1});
        }
        if(frontNode->right){
            q.push({frontNode->right , hd+1});
        }
        
    }
    for(auto i: topNodes){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    // BTNode<int> * root = takeInput();
    BTNode<int> * root = takeInputLevelWise();
    // printLevelWise(root);
    vector<int> ans = topView(root);
    for(auto i: ans){
        cout<<i<<" ";
    }
}