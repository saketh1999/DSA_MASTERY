//GFG: I Like GFG question -> its more challenging
//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-two-numbers-represented-by-linked-lists
//LeetCode: https://leetcode.com/problems/add-two-numbers/description/
//This Leetcode is very easy to slove
//GFG: Similar question
//https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-1-to-a-number-represented-as-linked-list
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////

//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
        Node* ReverseLL (Node* &head)
    {
        if(head==NULL)
        return NULL;

        Node*prev=NULL;
        Node*curr=head;
        while(curr!=NULL)
        {
            Node*forward= curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    Node* SumOfLL(Node* l1, Node*l2)
{
    int carry=0;
   // int v1=0,v2=0;
    Node* t1=l1;
    Node* t2=l2;
    Node* ans=new Node(-1);
    Node* ans_tail=ans;
    while(t1!=NULL || t2!=NULL || carry!=0)
    {
        int v1=0,v2=0;
        if(t1)
        v1=t1->data;
        if(t2)
        v2=t2->data;
        int sum= carry+v1+v2;

        carry=sum/10;
        sum=sum%10;
     
        //adding at the tail
        Node* element=new Node(sum);
        ans_tail->next=element;
        ans_tail=element;
        
        
        if(t1)
        t1=t1->next;
        if(t2)
        t2=t2->next;

    }
   
    return ans;
}
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node*l1=first;
        Node*l2=second;
        
        if(l1==NULL)
        return l2;
        if(l2==NULL)
        return l1;
        //first lets reverse the two linked list
        Node* l1_h=ReverseLL(l1);
        Node* l2_h=ReverseLL(l2);

        Node* ans= SumOfLL(l1_h,l2_h);
        ans=ReverseLL(ans->next);
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends