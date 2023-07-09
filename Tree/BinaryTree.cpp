#include <iostream>
#include <stack>
#include<queue>
#include<unordered_set>
using namespace std;
//This code contains
// How to build a tree using recursion
// How to build a tree in level order fashion
// Level Order Trav
// Inorder,Preorder and Postorder Trav (Recursively and iteratively)
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
            if(temp->left)
            {
                level.push(temp->left);
            }

            if(temp->right)
            {
                level.push(temp->right);
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
void inorderTrav_Iterative(Node* root)
{
    if(root==NULL)
    return;

    stack<Node*> st;
   
      Node* front= root;
    while(!st.empty() || front!=NULL)
    {
      
        
        while(front!=NULL)
        {
            st.push(front);
            front=front->left;
        }

        front=st.top();
        cout<<front->data<<" ";
        st.pop();

        front=front->right;

    }

}
void preorderTrav(Node* root)
{
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    preorderTrav(root->left);
    preorderTrav(root->right);

}
void preorderTrav_Iterative(Node* root)
{
    if(root==NULL)
    return;

    stack<Node*> st; 
    st.push(root);
   
    
    while(!st.empty() )
    {
        Node* front= st.top();
        st.pop();
        cout<<front->data<<" ";
        
        if(front->right)
        {
            st.push(front->right);
        }
        if(front->left)
        {
            st.push(front->left);
        }

    }

}
void postorderTrav(Node* root)
{
    if(root==NULL)
    return;

    postorderTrav(root->left);
    postorderTrav(root->right);
    cout<<root->data<<" ";
}
void postorderTrav_Iterative(Node* root)
{
    if(root==NULL)
    return;

    stack<Node*> treeStack;
    unordered_set<Node*> visitedNodeSet;
    Node* currNode = root;

    while (!treeStack.empty() || currNode != NULL) 
    {
        if (currNode != NULL) 
        {
            if (visitedNodeSet.count(currNode) > 0) 
            {
                // currNode has already been visited
                cout << currNode->data << " ";
                currNode = NULL;
            }
            else 
            {
                // first visit to currNode
                treeStack.push(currNode);
                if (currNode->right != NULL)
                    treeStack.push(currNode->right);
                
                visitedNodeSet.insert(currNode);
                currNode = currNode->left;
            }
        }
        else 
        {
            // currNode is NULL, pop next node from stack
            currNode = treeStack.top();
            treeStack.pop();
        }
    }

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
root=BuildTree(root);
//Input String= 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

//Level order creation of Binary Tree
//BuildLevelOrder(root);

//Level Order Traversal
cout<<"Level Order Traversal is as follows : ";
LevelOrderTraversal(root);
cout<<endl;

//Inorder Traversal
cout<<"Inorder Traversal: ";
inorderTrav(root);
cout<<endl;

//PreOrder Traversal
cout<<"Preorder Traversal: ";
preorderTrav(root);
cout<<endl;


//Post Order Traversal
cout<<"Postorder Traversal: ";
postorderTrav(root);
cout<<endl;

cout<<"Inorder Traversal: ";
inorderTrav_Iterative(root);
cout<<endl;

cout<<"Preorder Traversal: ";
preorderTrav_Iterative(root);
cout<<endl;

cout<<"Postorder Traversal: ";
postorderTrav_Iterative(root);
cout<<endl;
}