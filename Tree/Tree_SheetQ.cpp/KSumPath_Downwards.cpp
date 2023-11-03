//GFG:https://practice.geeksforgeeks.org/problems/k-sum-paths/1
////////////////////////////////////////////////
/*
                SOLUTION 1
*/
////////////////////////////////////////////////

// -> O(N^2) Solution -> will work if we have to print the path 

class Solution{
  public:
    void solve(Node* root,int k, int & count, vector<int> &ans)
    {
        if(root==NULL)
        return;
        
        ans.push_back(root->data);
        
        //go to left
        solve(root->left,k,count,ans);
        
        //go to right
        solve(root->right,k,count,ans);
        
        int sum=0;
        int size=ans.size();
        for(int i= size-1;i>=0;i--)
        {
            sum+=ans[i];
            if(sum==k)
            count++;
        }
        //back tracking
        ans.pop_back();
    }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> ans;
        int count=0;

        solve(root,k,count,ans);
        return count;
    }
};
////////////////////////////////////////////////
/*
                SOLUTION 2
*/
////////////////////////////////////////////////

// -> O(N) solution , SC-> O(height of tree)



//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
  public:
  void solve(Node* root , int k, int &count, unordered_map<int,int> &mp, int prev)
  {
      if(root==NULL)
      return;
      
      //add the current node values to prev and store it in curr
      //(represents curr state value)
      int curr= prev+root->data;
      
      if(mp.find(curr-k)!=mp.end())
      {
          count+=mp[curr-k];
      }
      //If Curr adds up to K , increment count
      if(curr==k)
      count++;
      
      //add the curr sum to the map, to check recursively
      mp[curr]++;
      
      //go to left
      solve(root->left,k,count,mp,curr);
      
      //got to right
      solve(root->right,k,count,mp,curr);
      
      //backtracking the added sum
      mp[curr]--;
      
  }
    int sumK(Node *root,int k)
    {
        // code here 
        int count=0;
        int prev=0;
        // mp.first -> Stores the current sum value
        // mp.second-> Stores the number of time the above sum appeared
        unordered_map<int,int> mp;
        solve(root,k,count,mp,prev);
        return count;
    }
};