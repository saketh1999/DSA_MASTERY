//GFG: https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////
int preorderTrav(Node* root, int &count)
{
    if(root==NULL)
    {
        
        return count;
    }
    if(root->left==NULL && root->right==NULL)
    count++;
    preorderTrav(root->left,count);
    preorderTrav(root->right,count);
    
    return count;
}
int countLeaves(Node* root)
{
  // Your code here
  int count=0;
  
  return preorderTrav(root,count);
}