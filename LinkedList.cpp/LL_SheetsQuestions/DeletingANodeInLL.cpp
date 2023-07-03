//Leetcode: https://leetcode.com/problems/delete-node-in-a-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* trav=node->next;
         ListNode* prev=node;
        while(trav!=NULL)
        {
            node->val=trav->val;
            trav=trav->next;
            prev=node;
            node=node->next;
        }
        prev->next=NULL;



    }
};