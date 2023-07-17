//GFG: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////

class Solution{
    private:
    int isBalanced(Node* root, bool & ans)
    {
        if(root==NULL)
        return 0;
        
        int left=isBalanced(root->left,ans);
        int right=isBalanced(root->right,ans);
        
        if(abs(left-right)>1)
        ans=false;
        
        return max(left,right)+1;
        
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        bool ans=true;
        isBalanced(root,ans);
        return ans;
    }
};