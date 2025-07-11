class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElem = *max_element(nums.begin(), nums.end());
        long long result = 0;

        int left = 0;
        int count = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == maxElem) count++;

            while (count >= k) {
                // Count subarrays starting at left and ending from right to end
                result += (n - right);
                if (nums[left] == maxElem) count--;
                left++;
            }
        }

        return result;
    }
};
