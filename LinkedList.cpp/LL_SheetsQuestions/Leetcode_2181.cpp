//Leetcode: https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode* ans=new ListNode(-1);
        ListNode* ans_head=ans;
        ListNode*trav=head->next;

        while(trav!=NULL)
        {
            if(trav->val==0)
            {
                ListNode* ans_next=new ListNode(sum);
                sum=0;
                ans_head->next=ans_next;
                ans_head=ans_next;
                trav=trav->next;
            }
            else{
                sum+=trav->val;
                trav=trav->next;
            }
        }
        return ans->next;
    }
};