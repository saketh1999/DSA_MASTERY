# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev=None
        curr=head
        if curr:

            nxt=curr.next

        while curr:

            curr.next = prev
            prev = curr
            curr=nxt
            if nxt:
                nxt=nxt.next
            # print(prev.val,curr.val)

     
        
        return prev