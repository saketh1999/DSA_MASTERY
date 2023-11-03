//GFG: https://practice.geeksforgeeks.org/problems/symmetric-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool sym_helper(Node* root1, Node* root2 )
    {
          if(root1 == NULL || root2 ==NULL)
           {
               if(root1==root2)
               return true;
               else 
               return false;
           } 
        
     
        
            bool leftSubTree= sym_helper(root1->left,root2->right);
            if(root1->data!=root2->data)
            
            {
                    return false;
            }
            
            bool rightSubTree= sym_helper(root1->right,root2->left);
            
            return leftSubTree && rightSubTree;
           
       
        
    }
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root==NULL)
	    return true;
	    
	    return sym_helper(root->left,root->right); 
    }
};