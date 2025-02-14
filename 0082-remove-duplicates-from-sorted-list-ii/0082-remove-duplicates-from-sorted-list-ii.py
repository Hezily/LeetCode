# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)  # Dummy node before the head
        dummy.next = head
        prev = dummy  # Previous distinct node
        
        while head:
            if head.next and head.val == head.next.val:  # Found duplicates
                while head.next and head.val == head.next.val:
                    head = head.next  # Skip all duplicates
                prev.next = head.next  # Remove duplicates
            else:
                prev = prev.next  # Move forward when no duplicates
            
            head = head.next  # Move to the next node
        
        return dummy.next  # Return the new head
