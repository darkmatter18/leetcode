# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node_list = set()

        while head:
            if head in node_list:
                return head
            
            node_list.add(head)
            head = head.next
        return None