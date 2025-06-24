int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize) {
    bool* marked = (bool*)calloc(numsSize, sizeof(bool)); // to mark k-distant indices
    int* result = (int*)malloc(numsSize * sizeof(int));   // worst case all indices are valid
    *returnSize = 0;

    for (int j = 0; j < numsSize; j++) {
        if (nums[j] == key) {
            int start = (j - k) < 0 ? 0 : (j - k);
            int end = (j + k) >= numsSize ? numsSize - 1 : (j + k);
            for (int i = start; i <= end; i++) {
                marked[i] = true;
            }
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (marked[i]) {
            result[*returnSize] = i;
            (*returnSize)++;
        }
    }

    free(marked);
    return result;
}
