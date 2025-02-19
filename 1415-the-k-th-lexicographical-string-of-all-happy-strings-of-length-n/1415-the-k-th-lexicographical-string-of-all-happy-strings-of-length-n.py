class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        self.count = 0
        self.res = ""
        self.backtrack(n, k, [])
        return self.res
    
    def backtrack(self, n: int, k: int, cur: list) -> bool:
        # Base case
        if len(cur) == n:
            self.count += 1
            if self.count == k:
                self.res = "".join(cur)
                return True
            return False
        
        for ch in 'abc':  
            if cur and cur[-1] == ch:
                continue
            cur.append(ch)
            if self.backtrack(n, k, cur):
                return True
            cur.pop()
        
        return False
