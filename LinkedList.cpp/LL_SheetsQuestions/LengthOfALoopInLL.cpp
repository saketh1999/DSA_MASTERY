//GFG:https://practice.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)
        {
            head=NULL;
            delete head;
            return NULL;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prev=NULL;

        while(fast && fast->next)
        {
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;

            
        }
  
        prev->next=slow->next;
        slow->next=NULL;
        delete slow;
        return head;
    }
};