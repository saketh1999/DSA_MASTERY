//Leetcode:https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////

//I didnt get this solution in the first go, see how cleverly the dont
//update the curr if the values of curr and curr->next are matched
//and only if they are not matched they update the values
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        while(curr!=NULL && curr->next!=NULL)
        {
            if(curr->val==curr->next->val)
            {
                ListNode* forward= curr->next->next;
                ListNode* nodeToDelete=curr->next;
                delete nodeToDelete;
                curr->next= forward;

            }
            else{
                curr=curr->next;
            }
        }
        return head;
    }
};