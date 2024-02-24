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
TreeNode* helper(vector<int> inorder, int inStart, int inEnd, vector<int> postorder, int poStart, int poEnd, unordered_map<int,int> & in_mp)
{
    if(inStart > inEnd || poStart > poEnd)
    return NULL;

    TreeNode* root = new TreeNode(postorder[poEnd]);

    int root_ind = in_mp[postorder[poEnd]];
    int left_ind = root_ind - inStart;

    root->left = helper(inorder,inStart,root_ind-1,
                        postorder,poStart, poStart+left_ind-1,in_mp);

    root->right = helper(inorder,root_ind+1,inEnd,
                        postorder, poStart+left_ind, poEnd-1,in_mp);

    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> in_mp;
        for(int i=0;i<inorder.size();i++)
        {
            in_mp[inorder[i]] = i;
        }
        TreeNode* root = helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,in_mp);
        return root;
    }
};