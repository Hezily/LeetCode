class Solution:
    def constructDistancedSequence(self, n: int):
        used = [False] * (n + 1)
        seq = [0] * (2 * n - 1)
        self.backtrack(0, used, seq, n)
        return seq
    
    def backtrack(self, index: int, used: list, seq: list, n: int) -> bool:
        while index < len(seq) and seq[index] != 0:
            index += 1
        
        if index == len(seq):
            return True
        
        for i in range(n, 0, -1):
            if used[i]:
                continue
            
            if i == 1:
                seq[index] = i
                used[i] = True
                if self.backtrack(index + 1, used, seq, n):
                    return True
                seq[index] = 0
                used[i] = False
            elif index + i < len(seq) and seq[index + i] == 0:
                seq[index] = i
                seq[index + i] = i
                used[i] = True
                if self.backtrack(index + 1, used, seq, n):
                    return True
                seq[index] = 0
                seq[index + i] = 0
                used[i] = False
        
        return False
