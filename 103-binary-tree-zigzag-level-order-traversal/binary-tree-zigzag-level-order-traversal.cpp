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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
        return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        bool leftToRight = true;
        while(!q.empty())
        {
            int sizeOfQ = q.size();
            
            vector<int> curr_row;
           

            for(int i=0;i<sizeOfQ;i++)
            {
                TreeNode* front = q.front();
                q.pop();

                curr_row.push_back(front->val);
             

                if(front->left)
                    q.push(front->left);
                 if(front->right)
                    q.push(front->right);
            
            
            }
            
            if(leftToRight)
            {
                ans.push_back(curr_row);
                leftToRight = !leftToRight;
            }
            else{
                reverse(curr_row.begin(),curr_row.end());
                ans.push_back(curr_row);
                leftToRight = !leftToRight;
            }
        }
        return ans;
    }
};