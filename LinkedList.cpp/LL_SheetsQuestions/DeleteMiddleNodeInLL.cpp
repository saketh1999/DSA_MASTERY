 //LeetCode: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
 ////////////////////////////////////////////////
/*
                SOLUTION 1
*/
////////////////////////////////////////////////
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;

            
        }
        ListNode*middle=slow;

        slow=head;
        while(slow->next!=middle)
        {
            slow=slow->next;
        }
        slow->next=middle->next;
        middle->next=NULL;
        delete middle;
        return head;
    }
};

////////////////////////////////////////////////
/*
                SOLUTION 2
*/
////////////////////////////////////////////////
//Same Concept as previous a bit of optimized way of traversing

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