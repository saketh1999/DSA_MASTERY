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
    TreeNode * helper(vector<int>& preorder, int preStart , int preEnd, vector<int>& inorder, 
                        int inStart, int inEnd, unordered_map<int,int>& in_map)
    {
        if(preStart>preEnd || inStart>inEnd)
        {return NULL;}

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = in_map[root->val]; //getting the index of the val from the inorder trav
        int numLeft = inRoot - inStart; //getting the left subtree len

        root->left = helper(preorder,preStart+1, preStart+numLeft, 
                            inorder,inStart,inRoot-1, in_map);

        root->right = helper(preorder,preStart+numLeft+1, preEnd, 
                            inorder,inRoot+1,inEnd, in_map);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> in_mp; // (value : i)
        for(int i=0;i<inorder.size();i++)
        {
            in_mp[inorder[i]] = i;
        }
        TreeNode* root = helper(preorder,0,preorder.size()-1,
                                inorder,0,inorder.size()-1, in_mp);
        
        return root;

    }
};