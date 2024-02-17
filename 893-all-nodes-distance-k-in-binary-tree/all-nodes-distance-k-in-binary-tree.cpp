/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode * root,unordered_map<TreeNode*,TreeNode*> &mp)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            auto front = q.front();
            q.pop();

            if(front->left)
            {
                mp [front->left] = front;
                q.push(front->left);
            }
            
            if(front->right)
            {
                mp[front->right] = front;
                q.push(front->right);
            }
            
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL)
        return {};

        unordered_map<TreeNode*,TreeNode*> mp; // (child=>parent)
        helper(root,mp);//parent map ready
        
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        int curr_dis = 0;
        visited[target] = true;
        while(!q.empty())
        {
            
            int size = q.size();
            if(curr_dis++ == k) break;

            for(int i = 0 ; i<size; i ++)
            {
                 auto front = q.front();
                 q.pop();

                 if(front->left && !visited[front->left])
                 {
                     q.push(front->left);
                     visited[front->left]=true;
                     
                 }

                 if(front->right && !visited[front->right])
                 {
                     q.push(front->right);
                     visited[front->right]=true;
                     
                 }

                 
                 if(mp[front] && !visited[mp[front]])
                 {
                     q.push(mp[front]);
                     visited[mp[front]]=true;
                     
                 }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

    }
};