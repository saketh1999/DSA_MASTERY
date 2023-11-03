//GFG: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
////////////////////////////////////////////////
/*
                SOLUTION 1
*/
////////////////////////////////////////////////

//Using Level order Traversal

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

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   if(root==NULL)
   return {};
   queue<Node*> q;
   q.push(root);
   q.push(NULL);
   vector<int> ans;
   ans.push_back(root->data);
   
   while(!q.empty())
   {
       Node* front=q.front();
       q.pop();
       
       if(front==NULL)
       {
           
           
           
           
           if(!q.empty())
           {
               ans.push_back(q.front()->data);
               q.push(NULL);
           }

       }
       else{
              if(front->left)
              q.push(front->left);
              if(front->right)
              q.push(front->right);
       }
       
    
   }
   return ans;
}
////////////////////////////////////////////////
/*
                SOLUTION 2
*/
////////////////////////////////////////////////

//Using Recusion

//Function to return a list containing elements of left view of the binary tree.
void leftViewHelper(Node * root, int lvl , vector<int> & ans)
{
    if(root==NULL)
    return;
    
    if(lvl==ans.size())
    ans.push_back(root->data);
        
    if(root->left)
    leftViewHelper(root->left,lvl+1,ans);
    
    if(root->right)
    leftViewHelper(root->right,lvl+1,ans);
    
}
vector<int> leftView(Node *root)
{
   // Your code here
   if(root==NULL)
   return {};
   
   vector<int> ans; 
   
   leftViewHelper(root,0,ans);
   
   return ans;
}