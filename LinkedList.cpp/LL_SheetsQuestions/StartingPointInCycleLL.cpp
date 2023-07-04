//Leetcode: https://leetcode.com/problems/linked-list-cycle-ii/description/
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // if(head->next=head)
        // return head;
        if(head==NULL || head->next==NULL)
         return NULL;

        
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            {
                slow=head;
                break;
            }
        }
        if(fast==NULL || fast->next==NULL) //if no loop is present in the given LL
        return NULL;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};