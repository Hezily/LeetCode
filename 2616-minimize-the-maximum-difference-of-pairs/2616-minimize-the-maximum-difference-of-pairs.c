int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int isPossible(int* nums, int numsSize, int val, int p) {
    int count = 0;
    int i = 1;
    while (i < numsSize) {
        if (nums[i] - nums[i - 1] <= val) {
            count++;
            i += 2;
        } else {
            i++;
        }
    }
    return count >= p;
}

int minimizeMax(int* nums, int numsSize, int p) {
    qsort(nums, numsSize, sizeof(int), compare);

    int low = 0, high = nums[numsSize - 1];
    int ans = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(nums, numsSize, mid, p)) {
            if (mid < ans)
                ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
