//GFG: https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue <Node*> q;
    stack<Node* >s;
    vector<int> ans;
    q.push(root);
    
    while(!q.empty())
    {
        Node* front= q.front();
        
        s.push(front);
        q.pop();
        if(front->right)
        {
            q.push(front->right);
        }
        if(front->left)
        {
            q.push(front->left);
            
        }
        

    }
    while(!s.empty())
    {
        ans.push_back(s.top()->data);
        s.pop();
    }
    return ans;
}