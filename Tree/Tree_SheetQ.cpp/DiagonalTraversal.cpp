//GFG: https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

////////////////////////////////////////////////
/*
                SOLUTION 1
*/
////////////////////////////////////////////////
//TC -> O(N log N)

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

void diagonal_helper(Node*root, int lvl, map<int, vector<int> > &aux)
{
    if(root==NULL)
    return;
    
    aux[lvl].push_back(root->data);
    
    if(root->left)
    diagonal_helper(root->left,lvl+1, aux);
    if(root->right)
    diagonal_helper(root->right,lvl,aux);
}
vector<int> diagonal(Node *root)
{
   // your code here
   map<int, vector<int> > aux;
   
   diagonal_helper(root,0,aux);
   
   vector<int> ans;
   
   for(auto x :  aux)
   {
       for(auto y: x.second)
       ans.push_back(y);
   }
   return ans;
}
////////////////////////////////////////////////
/*
                SOLUTION 2
*/
////////////////////////////////////////////////

//TC -> O(N)

vector<int> diagonal(Node *root)
{
   // your code here
   
   queue<Node*> q;
   
   vector<int> res;
   
   q.push(root);
   
   while(!q.empty())
   {
       int size= q.size();// number of the left elements remaining in Queues
       vector<int> ans;
       
       while(size--)
       {
            Node* front = q.front();
            q.pop();
        
            while(front)
            {
                ans.push_back(front->data);
                
                if(front->left)
                q.push(front->left);
                
                front=front->right;
            }
       
       }
       for(auto x : ans)    
       res.push_back(x);
   }
   return res;
}