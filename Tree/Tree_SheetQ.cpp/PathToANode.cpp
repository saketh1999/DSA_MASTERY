//InterViewBit:https://www.interviewbit.com/problems/path-to-given-node/

////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////

 bool solution_helper(TreeNode* root, int B, vector<int> &ans)
 {
     if(root==NULL)
     return false;
     
     ans.push_back(root->val);
     
     if(root->val==B)
     return true;
     
     bool leftT= solution_helper(root->left,B,ans);
     bool rightT= solution_helper(root->right,B,ans);
     

     //If any of the left/right Tree give True
     //We must return true 
     //This indicates that we have the required node present in
     //the left or the right part of the tree
     if(leftT || rightT )
     return true;
     
     //Back track only after checking if both the left and right 
     //nodes of the curr Node also return false.
     ans.pop_back();
     return false;
     
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    
    solution_helper(A,B,ans);
    return ans;
    
}