# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        start = ListNode()
        head = ListNode(0, start)
        while list1 != None or list2 != None:
            if list1 == None:
                l = ListNode(list2.val)
                start.next = l
                list2 = list2.next
            elif list2 == None:
                l = ListNode(list1.val)
                start.next = l
                list1 = list1.next
            elif list1.val <= list2.val:
                l = ListNode(list1.val)
                start.next = l
                list1 = list1.next
            else:
                l = ListNode(list2.val)
                start.next = l
                list2 = list2.next
            start = start.next
        
        head = head.next.next
        return head
