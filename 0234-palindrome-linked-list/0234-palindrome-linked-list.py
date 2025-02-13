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
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True
        
        # Step 1: Find the middle of the linked list (slow will be at mid)
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        # Step 2: Reverse the second half of the list
        prev = None
        while slow:
            temp = slow.next
            slow.next = prev
            prev = slow
            slow = temp
        
        # Step 3: Compare first half and reversed second half
        left, right = head, prev
        while right:  # Since right half may be shorter
            if left.val != right.val:
                return False
            left = left.next
            right = right.next
        
        return True
