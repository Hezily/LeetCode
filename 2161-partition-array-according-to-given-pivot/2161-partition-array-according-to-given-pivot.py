class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        less = []
        eq = []
        gre = []

        for num in nums:
            if num < pivot:
                less.append(num)
            elif num == pivot:
                eq.append(num)
            else:
                gre.append(num)
        
        return less + eq + gre
