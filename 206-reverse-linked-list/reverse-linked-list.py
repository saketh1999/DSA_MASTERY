# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev1=None
        prev2=None
        curr=head

        while curr:
            prev1=curr
            curr=curr.next
            prev1.next=prev2
            prev2=prev1
        
        return prev1