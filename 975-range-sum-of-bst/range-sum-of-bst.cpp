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
    int traverse_BST(TreeNode * root, int l, int h,int &sum)
    {
        if(root==NULL)
        return sum;
        traverse_BST(root->left,l,h,sum);

        if(root->val>=l && root->val<=h)
            {
                sum+=root->val;
        
            }
        
        traverse_BST(root->right,l,h,sum);

        return sum;

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        int ans = traverse_BST(root,low,high,sum);
        return ans;
    }
};