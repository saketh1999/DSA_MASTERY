# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        next = head
        temp = head
        while temp:
            next = temp.next
            temp.next = prev
            prev = temp
            temp = next
        head = temp
        return prev
