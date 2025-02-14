class ProductOfNumbers:
    def __init__(self):
        self.list = []
    
    def add(self, num: int) -> None:
        if num == 0:
            self.list.clear()
            return
        prev = 1 if not self.list else self.list[-1]
        self.list.append(prev * num)
    
    def getProduct(self, k: int) -> int:
        s = len(self.list)
        if s < k:
            return 0
        elif s == k:
            return self.list[-1]
        else:
            return self.list[-1] // self.list[-1 - k]

# Example usage:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)