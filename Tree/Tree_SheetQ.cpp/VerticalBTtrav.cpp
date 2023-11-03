//GFG:https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        
        //below aux map will help us to find the sol
        // first value in map is Horizontal distance
        // second value in map another map to store level and nodes
        
        map<int, map<int,vector<int> > > aux;
        
        //making a queue to do level order traversal
        
        queue<pair<Node*,pair<int, int> > > q;
        //queue contains HD and Level along with node
        
        //Pushing 1st node in
        
        q.push(make_pair(root,make_pair(0,0)));
        
        //Level Order Trav
        
        while(!q.empty())
        {
            pair<Node*,pair<int, int> > front= q.front();
            q.pop();
            
            //creating variables for ease
            Node* temp= front.first;
            int hd=front.second.first;
            int lvl= front.second.second;
            
            //now push this into the map
            aux[hd][lvl].push_back(temp->data);
            
            //While left is true
            if(temp->left)
            {
                q.push(make_pair(temp->left,make_pair(hd-1,lvl+1)));
            }
            if(temp->right)
            {
                q.push(make_pair(temp->right,make_pair(hd+1,lvl+1)));
            }
        }
        //sol vector
        vector<int> sol;
        for(auto x : aux)
        {
            for(auto y: x.second)
            {
                for(auto z: y.second)
                {
                    sol.push_back(z);
                }
            }
        }
        return sol;
    }
};
