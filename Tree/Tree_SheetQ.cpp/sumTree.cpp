//GFG:https://practice.geeksforgeeks.org/problems/sum-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////
class Solution
{
    private:
    int sumOfAllNode(Node* root, int &sum)
    {
        if(root==NULL)
        return 0;
       
    
        int left=sumOfAllNode(root->left,sum);
        int right=sumOfAllNode(root->right,sum);
        
        sum=root->data+left+right;
        //cout<<sum<<endl;
        return sum;
    }
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
          if(root->left==NULL && root->right==NULL)
            return true;
         int sum=0;
          sum=sumOfAllNode(root,sum);
     cout<<sum;
         sum-=root->data;
        
         return (root->data==sum)?true:false;
         
    }
};