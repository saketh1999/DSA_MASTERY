# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        temp = head
        while n and temp:
            temp=temp.next
            n-=1
        if temp is None:
            head=head.next
            return head
        curr=head
        while temp.next:
            curr=curr.next
            temp=temp.next


        curr.next=curr.next.next
        return head