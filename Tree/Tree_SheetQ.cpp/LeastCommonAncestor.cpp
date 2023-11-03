//GFG:https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    
    Node* lca_helper(Node* root, int n1,int n2)
    {
        //Base Condition
        if(root==NULL)
        {
            return NULL;
        }
        
        //Go to the left and right of the node
        Node* leftAns= lca_helper(root->left,n1,n2);
        Node* rightAns=lca_helper(root->right,n1,n2);
       
       //If both left and right are true 
       //return the current root (since it is the ancestor)
        if(leftAns && rightAns)
        return root;
        
        //if leftAns is true
        if(leftAns)
        {
            //This will check if the current node is one of the required nodes
            // if yes, the return that node itself
            //This is necessary in case one of the given nodes is the ancestor 
            if(root->data==n1)
            {
                return root;
            }
            if(root->data==n2)
            {
                return root;
            }
           
           //If the above is not true, the return this
            return leftAns;
        }
        
        
        if(rightAns)
        {
            //This will check if the current node is one of the required nodes
            // if yes, the return that node itself
            //This is necessary in case one of the given nodes is the ancestor 
            if(root->data==n1)
            {
                return root;
            }
            if(root->data==n2)
            {
                return root;
            }
            //If the above is not true, the return this
            return rightAns;
        }
       
        //Checking if the current node is one of the given nodes
        if(root->data==n1)
        {
            return root;
        }
        if(root->data==n2)
        {
            return root;
        }
        
        //If all of the above are false return NULL
        return NULL;
        
        
        
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       return lca_helper(root,n1,n2);
       
    }
};