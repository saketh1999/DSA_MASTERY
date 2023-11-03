//GFG:https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////

*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        //map will store the Horizontal distance and the visible Node's val
        map<int,int> aux;
        
        //Queue for Level order Trav
        queue<pair<Node*,int> > q;
        
        //pushing first val
        q.push(make_pair(root,0));
        
        while(!q.empty())
        {
            pair<Node*,int> temp = q.front();
            q.pop();
            
            //getting each value of the temp variable
            int hd= temp.second;
            Node* front= temp.first;
            
            if(aux.find(hd)==aux.end())
            aux[hd]=front->data;
            
            //Check if left node available
            if(front->left)
            {
                q.push(make_pair(front->left,hd-1));
            }
            if(front->right)
            {
                q.push(make_pair(front->right,hd+1));
            }
            
            
        }
        //solution vector
        vector<int> sol;
        for(auto x: aux)
        {
            sol.push_back(x.second);
            
        }
        return sol;
    }

};