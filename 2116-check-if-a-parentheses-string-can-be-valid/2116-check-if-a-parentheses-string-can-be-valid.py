class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        n = len(s)
        if n % 2 != 0:
            return False
        
        # Left-to-right pass
        open_needed = 0
        unlocked_count = 0
        for i in range(n):
            if locked[i] == '0':  # Unlocked character
                unlocked_count += 1
            elif s[i] == '(':
                open_needed += 1
            else:  # s[i] == ')'
                if open_needed > 0:
                    open_needed -= 1
                elif unlocked_count > 0:
                    unlocked_count -= 1
                else:
                    return False
        
        # Right-to-left pass
        close_needed = 0
        unlocked_count = 0
        for i in range(n - 1, -1, -1):
            if locked[i] == '0':  # Unlocked character
                unlocked_count += 1
            elif s[i] == ')':
                close_needed += 1
            else:  # s[i] == '('
                if close_needed > 0:
                    close_needed -= 1
                elif unlocked_count > 0:
                    unlocked_count -= 1
                else:
                    return False
        
        return True
    