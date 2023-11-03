//GFG:https://practice.geeksforgeeks.org/problems/sum-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////
long int sumBTHelper(Node* root, long int &sum)
{
     if(root==NULL)
    return 0;
    
    int left=sumBT(root->left);
    int right=sumBT(root->right);
    
    sum=root->key+left+right;
    
    return sum;
}
long int sumBT(Node* root)
{
    // Code here
    long int sum=0;
   return sumBTHelper(root,sum);
}