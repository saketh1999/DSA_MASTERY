/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        if(root==NULL)
        return {};
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            pair<TreeNode*,pair<int,int>> front = q.front();
            q.pop();
           int value = front.first->val;
           int x_axis = front.second.first;
           int y_axis = front.second.second;
            mp[x_axis][y_axis].insert(value);

            if(front.first->left)
                q.push({front.first->left,{x_axis-1,y_axis+1}});
            if(front.first->right)
                q.push({front.first->right,{x_axis+1,y_axis+1}});

        }

        vector<vector<int> > ans;

        for(auto x : mp)
        {
            vector<int> col;
            for(auto y : x.second)
            {
                for(auto z: y.second)
                {
                    col.push_back(z);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};