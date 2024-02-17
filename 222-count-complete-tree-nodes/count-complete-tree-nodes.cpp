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
    int left_h(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        int h=0;

        while(root)
        {
            root=root->left;
            h++;
        }
        return h;
    }
    int right_h(TreeNode *root)
    {
         if(root==NULL)
        return 0;

        int h=0;

        while(root)
        {
            root=root->right;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
        return 0;

        int left = left_h(root);
        int right = right_h(root);

        if(left==right) return (1<<left)-1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};