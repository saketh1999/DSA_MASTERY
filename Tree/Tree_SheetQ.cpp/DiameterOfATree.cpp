//GFG: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
////////////////////////////////////////////////
/*
                SOLUTION 1
*/
////////////////////////////////////////////////
//O(N^2)solution

class Solution {
    private:
    int height(Node * root)
    {
        if(root==0)
        return 0;
        
        int left= height(root->left);
        int right= height(root->right);
        
        return max(left,right)+1;
    }
 
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        
      
        
        //O(N^2)solution
          if(root==NULL)
            return 0;
        int left=diameter(root->left);
        int right= diameter(root->right);
        int height_of_curr_node= height(root->left)+height(root->right)+1;
        return max(left,max(right,height_of_curr_node));

        }
};

////////////////////////////////////////////////
/*
                SOLUTION 2
*/
////////////////////////////////////////////////
//O(N) solution (Most optimised)
   pair<int,int> diameterFast(Node* root)
    {
        if(root==NULL)
        {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left_dia= diameterFast(root->left);
        pair<int,int> right_dia= diameterFast(root->right);
        
        // We are finding the following 3 values to determine the diameter of the tree
        
        //Diameter = MAX(diameter of LEFT SUBTREE, MAX(RIGHT SUBTREE, HEIGHT OF CURR NODE));
        
        int left= left_dia.first; // if the tree is only skewed to left
        int right= right_dia.first;//if the tree is only skewed to the right
        
        //Sum of the height of the left and right part of a nodes subtree.
        int left_right_heights= left_dia.second+right_dia.second+1;
        
        pair<int,int>ans;
        //diameter of the current node
        ans.first=max(left,max(right,left_right_heights));
        
        //Height of the current node
        ans.second=max(left_dia.second,right_dia.second)+1;
        
        return ans;
        
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        

        //O(N) solution (Most optimised)
        return diameterFast(root).first;
        
        
        }
};

