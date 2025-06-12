int maxAdjacentDistance(int* nums, int numsSize) {
    int maxDiff = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int nextIndex = (i + 1) % numsSize; // Ensures circular adjacency
        int diff = abs(nums[i] - nums[nextIndex]);
        if (diff > maxDiff) {
            maxDiff = diff;
        }
    }

    return maxDiff;
}
