//GFG: https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=segregate-even-and-odd-nodes-in-a-linked-list
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* even =new Node (-1);
        Node* even_tail=even;
        Node* odd =new Node(-1);
        Node*odd_tail=odd;
        
        Node* trav= head;
        Node* forward=NULL;
        while(trav!=NULL)
        {
            if(trav->data%2==0)
            {
                forward=trav->next;
                even_tail->next=trav;
                even_tail=trav;
                even_tail->next=NULL;
                trav=forward;
                
            }
            else
            {
                forward=trav->next;
                odd_tail->next=trav;
                odd_tail=trav;
                odd_tail->next=NULL;
                trav=forward;
            }
            //trav=trav->next;
        }
        if(odd->next!=NULL)
        {
            even_tail->next=odd->next;
        }
        //odd_tail->next=NULL;
        head=even->next;
        return head;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends