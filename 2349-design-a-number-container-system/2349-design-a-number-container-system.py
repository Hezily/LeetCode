class NumberContainers:
    def __init__(self):
        self.idx_to_number = {}  # Maps index to number
        self.number_to_idx = {}  # Maps number to a min-heap of indices

    def change(self, index: int, number: int) -> None:
        # Store the index-to-number mapping
        self.idx_to_number[index] = number
        
        # Insert index into the min-heap for the new number
        if number not in self.number_to_idx:
            self.number_to_idx[number] = []
        heapq.heappush(self.number_to_idx[number], index)

    def find(self, number: int) -> int:
        if number not in self.number_to_idx or not self.number_to_idx[number]:
            return -1
        
        # Remove stale indices
        while self.number_to_idx[number]:
            idx = self.number_to_idx[number][0]
            if self.idx_to_number.get(idx) == number:
                return idx
            heapq.heappop(self.number_to_idx[number])  # Lazy cleanup of outdated indices
        
        return -1
