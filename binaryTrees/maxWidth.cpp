int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(root == NULL)return ans;

        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            pair<TreeNode*,int> front = q.front();
            q.pop();

            TreeNode* frontNode = front.first;
            int hd = front.second;

            mp[hd]= frontNode->val;
            if(frontNode->left){
                q.push({frontNode->left , hd-1});
            }
            if(frontNode->right){
                q.push({frontNode->right,hd+1});
            }

        }
        // for(auto i:mp.first){

        // }
        ans = mp.size();
        return ans;
    }