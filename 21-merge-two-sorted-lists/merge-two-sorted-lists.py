# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        dummy_Head=dummy
        l1=list1
        l2=list2
        while l1 and l2:
            if l1.val < l2.val:
                dummy.next=l1
                l1 = l1.next
                
            else:
                dummy.next=l2
                l2=l2.next

            dummy=dummy.next
            dummy.next=None
        
        if l1:
            dummy.next=l1
        if l2:
            dummy.next=l2
        
        return dummy_Head.next