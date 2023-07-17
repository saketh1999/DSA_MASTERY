//GFG : https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

////////////////////////////////////////////////
/*
                SOLUTION 1
*/
////////////////////////////////////////////////

//TC O(N) , SC O(1)
//I didnt like and understand this solution much, cause of the merging
void insertAtTail(Node* &tail,Node* curr)
{
    tail->next=curr;
    tail=curr;
    
}
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* zeroHead =new Node(-1);
        Node* zeroTail= zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail= oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail= twoHead;
        Node*trav=head;
        while(trav!=NULL)
        {
            if(trav->data==0)
            {
                insertAtTail(zeroTail,trav);
            }
            else if(trav->data==1)
            {
                insertAtTail(oneTail,trav);
            }
            else if(trav->data==2)
            {
                insertAtTail(twoTail,trav);
            }
            trav=trav->next;
        }
      
        if(oneHead -> next!=NULL)
        {
            zeroTail->next=oneHead->next;
        }
        else{
            zeroTail->next=twoHead->next;
        }
        oneTail->next=twoHead->next;
        twoTail->next=NULL;
        //updating the head
        head=zeroHead->next;
        
        delete twoHead;
        delete oneHead;
        delete zeroHead;
        return head;
       
        
         
         
        
    }
////////////////////////////////////////////////
/*
                SOLUTION 2
*/
////////////////////////////////////////////////

//I wrote the merge code myself
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* zeroHead=new Node(-1);
        Node * zeroTail= zeroHead;
        
        Node* oneHead= new Node(-1);
        Node * oneTail= oneHead;
        
        Node * twoHead=new Node(-1);
        Node * twoTail = twoHead;
        
        Node *curr=head;
        
        while(curr!=NULL)
        {
             Node* forward=curr->next;
            if(curr->data==0)
            {
               
                zeroTail->next=curr;
                zeroTail=curr;
                zeroTail->next=NULL;

            }
            else if(curr->data==1)
            {

                oneTail->next=curr;
                oneTail=curr;
                oneTail->next=NULL;

            }
            else if(curr->data==2)
            {
                twoTail->next=curr;
                twoTail=curr;
                twoTail->next=NULL;

            }
            curr=forward;
        }
         
        Node* ans= new Node(-1);
        Node* ans_tail= ans;
        
        if(zeroHead->next!=NULL)
        {
            ans_tail->next=zeroHead->next;
            ans_tail=zeroTail;
        }
        if(oneHead->next!=NULL)
        {
            ans_tail->next=oneHead->next;
            ans_tail=oneTail;
        }
        if(twoHead->next!=NULL)
        {
            ans_tail->next=twoHead->next;
            ans_tail=twoTail;
        }
        head=ans->next;
        delete ans;
        delete oneHead;
        delete twoHead;
        delete zeroHead;
     
        return head;
        
        
        
    }
};
