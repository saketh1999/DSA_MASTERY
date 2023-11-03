//GFG:https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////
Node* solve(Node * root, int &k, int search)
{
    if(root==NULL)
    return NULL;
    
    //If the current node is the node we are searching for return curr node
    if(root->data==search)
    {
         return root;
    }
    
    //checking if Left/right subtree has the required node
    Node* leftT= solve(root->left,k,search);
    Node* rightT= solve(root->right,k,search);
    

    //If any one has it, do the following checks
    if(leftT || rightT)
    {
        if(k==0)
        {
            //So that subsequent checks dont affect the k value
            k=INT_MAX;
            return root;
        }
        else{
            k--; //decrement k value going up each level
            
            if(leftT) // return left if leftT is true
            return leftT;
            if(rightT) //return right if rightT is true
            return rightT;
        }
    }
       
    
    return NULL;
    
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
   
    k--;//reducing the value by 1, since we do not count the node itself
    
    Node* ans=solve(root,k,node);
    
    //This condition is important
    //1. if ans==NULL -> means no node with the given value is found
    //2. if ans->data==node => the k value is greater than the actual
    // no. of ancestor for node
    if(ans==NULL || ans->data==node)
    return -1;
    
    //return the ans
    return ans->data;
}