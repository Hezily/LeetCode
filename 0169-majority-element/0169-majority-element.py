class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # Initialize variables to track the candidate and its count
        candidate = None
        count = 0

        # Step 1: Find the candidate for majority element
        for num in nums:
            if count == 0:
                # Set the current number as the candidate
                candidate = num
                count = 1
            elif num == candidate:
                # Increment count if current number matches the candidate
                count += 1
            else:
                # Decrement count otherwise
                count -= 1

        # Step 2: Return the candidate (guaranteed to be the majority element)
        return candidate
