class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        return self.at_least_k(k, word) - self.at_least_k(k + 1, word)

    def at_least_k(self, k: int, word: str) -> int:
        count = 0
        cur_consonant = 0
        freq = {}
        left = 0
        n = len(word)
        vowels = {'a', 'e', 'i', 'o', 'u'}
        vowel_count = 0

        for right in range(n):
            ch = word[right]
            
            freq[ch] = freq.get(ch, 0) + 1
            
            if ch not in vowels:
                cur_consonant += 1

            if ch in vowels and freq[ch] == 1:
                vowel_count += 1

            while cur_consonant >= k and vowel_count == 5:
                count += (n - right)
                left_char = word[left]
                
                if left_char not in vowels:
                    cur_consonant -= 1
                
                if left_char in vowels and freq[left_char] == 1:
                    vowel_count -= 1
                    
                freq[left_char] -= 1
                if freq[left_char] == 0:
                    del freq[left_char]
                
                left += 1

        return count
