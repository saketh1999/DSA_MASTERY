//GFG:https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////
//User function Template for C++

class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        Node* curr = root;
        
        while(curr!=NULL)
        {
            if(curr -> left)
            {
                //Find the predecessor
                Node* predecessor = curr->left;
                while(predecessor->right)
                {
                    predecessor = predecessor->right;
                }
                
                predecessor->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr -> right;
        }
        
    }
};