int maximumDifference(int* nums, int numsSize) {
    int min_so_far = nums[0];
    int max_diff = -1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > min_so_far) {
            int diff = nums[i] - min_so_far;
            if (diff > max_diff)
                max_diff = diff;
        } else {
            min_so_far = nums[i]; // update the minimum
        }
    }

    return max_diff;
}
