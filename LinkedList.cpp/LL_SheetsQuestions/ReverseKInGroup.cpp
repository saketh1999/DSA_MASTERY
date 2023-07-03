//Leetcode link: https://leetcode.com/problems/reverse-nodes-in-k-group/
// O(1) space compelexity->//YT Explaination: https://www.youtube.com/watch?v=Of0HPkk3JgI


//I Solved this question as following (but has O(N) spce complexity)

//Coded this on Leetcode:
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
private:
ListNode* ReverseKLL(ListNode*head, int k)
{
    if(head==NULL )
    {
        
        return NULL;
    }
    int count=0;

    ListNode* curr=head;
    ListNode* prev=NULL;
    while(count<k && curr!=NULL)
    {
         ListNode* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    if(curr!=NULL)
    head->next =ReverseKLL(curr,k);

    return prev;

}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * prev=NULL;
        ListNode * curr=NULL;
        head= ReverseKLL(head,k);

        int len=0;
        ListNode* trav=head;
        while(trav!=NULL)
        {
            len++;
            trav=trav->next;
        }
        //cout<<len;
        int no_elements_to_be_shifted=(len%k);
        int to_trav=len-no_elements_to_be_shifted-1;

        trav=head;
        while(to_trav--)
        {
            trav=trav->next;
        }
       
        ListNode*lastHead=ReverseKLL(trav->next,no_elements_to_be_shifted);
        trav->next=lastHead;
        return head;


    }
};
////////////////////////////////////////////////