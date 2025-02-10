class Solution:
    def clearDigits(self, s: str) -> str:
        sb = []
        for char in s:
            if not char.isdigit():
                sb.append(char)
            elif sb:
                sb.pop()
        return ''.join(sb)
