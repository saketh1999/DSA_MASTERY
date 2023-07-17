//GFG:https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	bool flag=false;
    	
    	queue<Node*> q;
    	vector<int> result;
    	
    	q.push(root);
    	
    	while(!q.empty())
    	{
    	    int size= q.size();
    	    vector<int> ans(size);
    	    
    	    for(int i=0;i<size;i++)
    	    {
    	        Node* front=q.front();
    	        q.pop();
    	        int index= flag? i: size-i-1;
    	        ans[index]= front->data;
    	        
    	         if(front->right)
    	        q.push(front->right);
    	         if(front->left)
    	        q.push(front->left);
    	        
    	    }
    	    
    	    flag=!flag;
    	    
    	    for(int x:ans)
    	    result.push_back(x);
    	    
    	  
    	}
    	return result;
    }
};