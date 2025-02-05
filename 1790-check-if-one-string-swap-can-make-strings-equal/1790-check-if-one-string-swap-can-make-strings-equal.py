class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        # If the strings are already equal, return True
        if s1 == s2:
            return True
        
        # Find indices where the characters differ
        diff = [(c1, c2) for c1, c2 in zip(s1, s2) if c1 != c2]
        
        # There must be exactly two differences, and swapping them should make the strings equal
        return len(diff) == 2 and diff[0] == diff[1][::-1]
