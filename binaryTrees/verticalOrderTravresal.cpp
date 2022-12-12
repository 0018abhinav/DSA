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

vector<int> verticalOrder(BTNode<int>* root){
    vector<int> ans;
    if(root == NULL) return ans;
    map<int ,map<int, vector<int>>> nodes;
    //  hd       lvl    nodes
    queue<pair<BTNode<int>* , pair<int,int>>> q;
    //         node                 hd  lvl  bcoz to map nodes , horizontal dist and level is required

    q.push(make_pair(root, make_pair(0,0)));

    while(!q.empty()){
        pair<BTNode<int>* , pair<int,int>> front = q.front();
        q.pop();

        int hd = front.second.first;
        int lvl = front.second.second;
        BTNode<int>* frontNode = front.first;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, make_pair(hd+1 , lvl+1)));
        }

    }

    for(auto i:nodes){
        for(auto j : i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;

}
// vector<int> verticalOrder(BTNode<int>* root){
//     vector<int> ans;
//     if(root == NULL) return ans;
//     map<int , vector<int>> nodes;
//     //  hd       lvl    nodes
//     queue<pair<BTNode<int>* , int>> q;
//     //         node                 hd  lvl  bcoz to map nodes , horizontal dist and level is required

//     q.push(make_pair(root, 0));

//     while(!q.empty()){
//         pair<BTNode<int>* , int> front = q.front();
//         q.pop();

//         int hd = front.second;
//         // int lvl = front.second.second;
//         BTNode<int>* frontNode = front.first;

//         nodes[hd].push_back(frontNode->data);

//         if(frontNode->left){
//             q.push(make_pair(frontNode->left, hd-1));
//         }
//         if(frontNode->right){
//             q.push(make_pair(frontNode->right, hd+1));
//         }

//     }

//     for(auto i:nodes){
//         for(auto j : i.second){ 
//                 ans.push_back(j);
//         }
//     }
//     return ans;

// }

int main(){
    // BTNode<int> * root = takeInput();
    BTNode<int> * root = takeInputLevelWise();
    // printLevelWise(root);
    vector<int> ans = verticalOrder(root);
    for(auto i: ans){
        cout<<i<<" ";
    }

}
