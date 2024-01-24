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
    int solver(TreeNode* root, unordered_map<int,int>  mp,int odd)

    {
        if(root==NULL)
        return 0;
        
        
        mp[root->val]++;
        int odd_change;

        if(mp[root->val]%2!=0)
        {
            odd_change=1;
        }
        else{
            odd_change=-1;
        }
        odd+=odd_change;
        int res=0;
        if(root->left == NULL && root->right==NULL)
        {
            if(odd<=1)
            {
                return 1;
            }
            else return 0;
        }
        else{
            res = solver(root->left,mp,odd) + solver(root->right,mp,odd);
        }
        odd -= odd_change;
        mp[root->val]--;

        return res;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        int odd = 0;
        return solver(root,mp,odd);
    }
};