//Morris Traversal
//Advantage -> TC -> O(N) & SC O(1)
#include <iostream>
using namespace std;

struct Node 
{
int data;
Node* left;
Node* right;
};

//Only care about building this function

void morrisTrav(Node* root)
{
    if(root==NULL)
    return ; //The given Tree is Empty

    Node * curr =root;

    //Start the trav

    while(curr)
    {
        if(curr->left==NULL)
        {
            cout<<curr->data;
            curr=curr->right;
            
        }

        else{ //Left Child is present

            //Find the Predecessor

            Node * pre = curr->left;

            //Checking two conditions, if pre->right is not null
            // and pre right is not the curr node
            while(pre->right!=NULL && pre->right!= curr)
                 pre=pre->right; 

            if(pre->right == NULL)
            {
                pre->right=curr;
                curr=curr->left;
            }
            else{

                cout<<curr->data;
                pre->right=NULL;
                curr=curr->right;
            }
        }
    }

    
}
