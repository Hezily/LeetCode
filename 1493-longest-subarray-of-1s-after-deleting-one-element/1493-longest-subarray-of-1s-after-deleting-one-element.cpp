class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        bool isDeleted = false;
        int ans = 0;

        while (right < nums.size()) {
            int num = nums[right];

            if (num == 1) {
                ans = isDeleted ? max(ans, right - left) : max(ans, right - left + 1);
            } else {
                if (isDeleted) {
                    while (nums[left] == 1) {
                        left++;
                    }
                    left++;
                } else {
                    isDeleted = true;
                }
            }

            right++;
        }

        return isDeleted ? ans : ans - 1;
    }
};
