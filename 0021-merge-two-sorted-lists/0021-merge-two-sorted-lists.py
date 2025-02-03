# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(-1)  # Dummy node to act as the start of the merged list
        current = dummy  # Pointer to track the last node in the merged list

        while list1 and list2:  # Traverse both lists while they are not empty
            if list1.val < list2.val:  # Compare the values of the nodes
                current.next = list1  # Attach list1 node to merged list
                list1 = list1.next  # Move list1 pointer forward
            else:
                current.next = list2  # Attach list2 node to merged list
                list2 = list2.next  # Move list2 pointer forward

            current = current.next  # Move the merged list pointer forward
        
        # If one list is not fully traversed, attach the remaining part
        current.next = list1 if list1 else list2

        return dummy.next  # Return merged list, skipping the dummy node
     