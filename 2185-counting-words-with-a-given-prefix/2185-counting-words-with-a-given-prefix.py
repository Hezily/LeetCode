class Solution:
    def prefixCount(self, words: list[str], pref: str) -> int:
        count = 0
        length = len(pref)
        for word in words:
            if length <= len(word) and word[:length] == pref:
                count += 1
        return count
