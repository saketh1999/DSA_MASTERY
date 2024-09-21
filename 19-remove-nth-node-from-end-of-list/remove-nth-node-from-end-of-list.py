# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        temp = head
        for i in range(n):
            temp = temp.next
        if temp is None:
            head = head.next
            return head
        curr = head
        while temp.next is not None:
            curr = curr.next
            temp = temp.next
        if curr.next:
            curr.next = curr.next.next
        else :
            curr.next is None
        return head
