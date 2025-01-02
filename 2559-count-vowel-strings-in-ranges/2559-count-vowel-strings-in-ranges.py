class Solution:
    def vowelStrings(self, words: list[str], queries: list[list[int]]) -> list[int]:
        def is_vowel(word: str) -> int:
            vowels = {'a', 'e', 'i', 'o', 'u'}
            return 1 if word[0] in vowels and word[-1] in vowels else 0

        n = len(words)
        prefix_sum = [0] * n
        prefix_sum[0] = is_vowel(words[0])
        for i in range(1, n):
            prefix_sum[i] = prefix_sum[i - 1] + is_vowel(words[i])

        ans = []
        for l, r in queries:
            res = prefix_sum[r]
            if l > 0:
                res -= prefix_sum[l - 1]
            ans.append(res)
        
        return ans
