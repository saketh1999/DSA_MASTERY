//Leetcode:https://leetcode.com/problems/linked-list-cycle/description/
//GFG:https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1?page=1&category[]=Linked+List&sortBy=submissions&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-loop-in-linked-list


////////////////////////////////////////////////
/*
                SOLUTION 1
*/
////////////////////////////////////////////////
//using extra space O(N) using hash map < Node*, bool>

//TC O(N), SC O(N)
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
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool>visited;
        if(head==NULL)
        return false;
        if(head->next==NULL)
        return false;
        if(head->next==head)
        return true;
        ListNode* trav = head;
        visited[trav]=true;
        while(!visited[trav->next] && trav->next!=NULL)
        {
            trav=trav->next;
            visited[trav]=true;
        }

        if(visited[trav->next])
        return true;
        
        return false;
        
    }
};

////////////////////////////////////////////////
/*
                SOLUTION 2
*/
////////////////////////////////////////////////

//Fast and Slow pointers
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        if(head->next==head)
        return true;
        if(head->next==NULL)
        return false;
        Node* slow = head;
        Node * fast = head;
        
        while(fast!=NULL && fast->next!=NULL )
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            return true;
        }
        return false;
    }
};
