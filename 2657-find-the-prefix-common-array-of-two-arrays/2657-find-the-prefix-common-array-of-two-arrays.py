class Solution:
    def findThePrefixCommonArray(self, A, B):
        # Initialize the frequency map and result array
        n = len(A)
        freq = [0] * (n + 1)
        C = [0] * n
        count = 0
        
        # Iterate over the arrays to find the common elements' frequency
        for i in range(n):
            # Update frequency for A[i]
            freq[A[i]] += 1
            if freq[A[i]] == 2:
                count += 1
            
            # Update frequency for B[i]
            freq[B[i]] += 1
            if freq[B[i]] == 2:
                count += 1
            
            # Store the count of common elements up to the current index
            C[i] = count
        
        return C
   