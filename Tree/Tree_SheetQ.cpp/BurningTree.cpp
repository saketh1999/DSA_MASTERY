//GFG:https://practice.geeksforgeeks.org/problems/burning-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* constructMap(Node* root, int target, map<Node*,Node*> & nodeToParent)
    {
        //We will do Level order Traversal to form the queue and also 
        // find the target value
        
        //creating a LOT queue
        queue<Node*> q;
        q.push(root);
      
        nodeToParent[root]=NULL;
        Node* res=NULL;
        while(!q.empty())
        {
            
            Node* front= q.front();
            q.pop();
            
            //checking if the current node is the required target
            if(front->data==target)
            {
                res= front;
            }
            if(front->left)
            {
                //updating the parent for the left child
                nodeToParent[front->left]=front;
                //cout<<nodeToParent[front->left]->data<<endl;
                //pushing the left child into the queue
                q.push(front->left);
            }
            if(front->right)
            {
                //updating the parent for the right child
                nodeToParent[front->right]=front;
                //cout<<nodeToParent[front->right]->data<<endl;
                
                //pushing the right child into the queue
                 q.push(front->right);
            }
        }
        return res;
    }
    int burnTree(Node* root, map<Node*,Node*> mp)
    {
        //creating a visited array to keep track of the Nodes visited
        map<Node*,bool> visited;
        //Required answer
        int time=0;
        
        //Level Order Queue
        queue<Node*> q;
       
        q.push(root);
        visited[root]=true;
        
        while(!q.empty())
        {
            //Size return the number of elements in a given level
            int size= q.size();
            //this bool is used to tell if any new element was added in the next level
            bool flag=false;
            
            //We are doing this for loop, because we want
            //to do this for every element in a given level
            //This would mean we would need to traverse the elements using a for loop
            for(int i=0;i<size;i++)
            {
                Node* front = q.front();
                q.pop();
            
             
            //   cout<<front->data;
            //   cout<<mp[front];
                // we are checking if the left of current Front is valid
                // and if left of current Front is visited/not, 
                if( front->left && !visited[front->left] )
                {
                    flag=true;
                    
                    visited[front->left]=true;
                    q.push(front->left);
                }
                //we are checking if the right of current Front is valid
                // and if right of current Front is visited/not, 
                
                if(front->right && !visited[front->right] )
                {
                    flag=true;
                    visited[front->right]=true;
                    q.push(front->right);
                }
                
                //we are checking if the parent of the current Front is valid
                // and if parent of current Front is visited/not, 
                if( mp[front] && !visited[mp[front]] )
                {
                    flag=true;
                    visited[mp[front]]=true;
                    q.push(mp[front]);
                }
                
                
            }
            if(flag==true)//if any new element was added this would mean we burnt it
            {time++;}
        }
        return time;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        if(root==NULL)
        return -1;
        
        map<Node*, Node*> nodeToParent;
        Node* targt = constructMap(root,target,nodeToParent);
        int ans = burnTree(targt,nodeToParent);
        return ans;
        
    }
};