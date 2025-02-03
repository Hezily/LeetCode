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
        current = head  # Start from the head of the list
        
        while current and current.next:  # Traverse until we reach the end
            if current.val == current.next.val:  # Duplicate found
                current.next = current.next.next  # Skip the duplicate
            else:
                current = current.next  # Move forward
        
        return head  # Return modified list
