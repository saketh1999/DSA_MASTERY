//GFG: https://practice.geeksforgeeks.org/problems/level-order-traversal/1
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      queue<Node*> q;
      vector<int> ans;
      q.push(node);
      
      while(!q.empty())
      {
          Node* front= q.front();
          ans.push_back(front->data);
          q.pop();
          
          if(front->left)
          {
              q.push(front->left);
          }
          if(front->right)
          {
              q.push(front->right);
          }
          
      }
      return ans;
    }
};