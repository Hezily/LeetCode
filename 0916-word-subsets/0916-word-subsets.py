class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        # Function to calculate the frequency of characters in a word
        def get_freq(word):
            freq = [0] * 26
            for char in word:
                freq[ord(char) - ord('a')] += 1
            return freq

        # Calculate the maximum frequency of each character across all words in words2
        freq = [0] * 26
        for word in words2:  # M
            temp = get_freq(word)  # p
            for i in range(26):  # 26
                freq[i] = max(freq[i], temp[i])

        # Check each word in words1 to see if it satisfies the universal condition
        res = []
        for word in words1:  # n
            temp = get_freq(word)  # p
            is_universal = True
            for i in range(26):  # 26
                if freq[i] > temp[i]:
                    is_universal = False
                    break
            if is_universal:
                res.append(word)

        return res
   