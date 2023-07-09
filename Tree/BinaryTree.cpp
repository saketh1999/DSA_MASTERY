#include <iostream>
#include<queue>
using namespace std;
//This code contains
// How to build a tree using recursion
// How to build a tree in level order fashion
// Level Order Trav
// Inorder,Preorder and Postorder Trav
class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* BuildTree(Node* &root)
{
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    

    if(data==-1)
    {
        return NULL;
    }
    root= new Node(data);
    cout<<"Enter data for inserting data in left "<<data<<endl;
    Node* root_left=BuildTree(root->left);

    cout<<"Enter data for inserting data in right "<<data<<endl;
    Node* root_right=BuildTree(root->right);
   
    return root;

}
Node* LevelOrderTraversal(Node* root)
{
    queue<Node*> level;
    cout<<endl;
    level.push(root);
    level.push(NULL);//Now pushing null to indicating that Level 0 is completed
    
    while(!level.empty())
    {
        Node* temp= level.front();
        level.pop();
        if(temp==NULL)
        {
            cout<<endl;
            //check if queue no emplty
            if(!level.empty())
            {
                level.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->right)
            {
                level.push(temp->right);
            }
            if(temp->left)
            {
                level.push(temp->left);
            }

        }

    }
}
void inorderTrav(Node* root)
{
    if(root == NULL)
    return ;
    inorderTrav(root->left);
    cout<<root->data<<" ";
    inorderTrav(root->right);


}
void preorderTrav(Node* root)
{
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    preorderTrav(root->left);
    preorderTrav(root->right);

}
void postorderTrav(Node* root)
{
    if(root==NULL)
    return;

    postorderTrav(root->left);
    postorderTrav(root->right);
    cout<<root->data<<" ";
}
void BuildLevelOrder(Node* &root)
{
    queue<Node*> q;

    cout<<"Enter the root node value "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty())
    {
        Node* temp= q.front();
        q.pop();
        cout<<"Enter the left value of "<< temp->data<<endl;
        
        int leftData;
        cin>>leftData;
        if(leftData!=-1)
        {
            temp->left=new Node(leftData);
            q.push(temp->left);

        }
        cout<<"Enter the right value of "<< temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1)
        {
            temp->right=new Node(rightData);
            q.push(temp->right);

        }
    }
}
int main ()
{

Node* root =NULL;
//Recursively 
//root=BuildTree(root);
//Input String= 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

//Level order creation of Binary Tree
BuildLevelOrder(root);

//Level Order Traversal
cout<<"Level Order Traversal is as follows : ";
LevelOrderTraversal(root);
cout<<endl;

//Inorder Traversal
cout<<"Inorder Traversal: ";
inorderTrav(root);
cout<<endl;

//PreOrder Traversal
cout<<"Inorder Traversal: ";
preorderTrav(root);
cout<<endl;


//Post Order Traversal
cout<<"Inorder Traversal: ";
postorderTrav(root);
cout<<endl;


}