class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> distinctSet(nums.begin(), nums.end());
        int totalDistinct = distinctSet.size();

        int ans = 0;
        unordered_map<int, int> freq;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            freq[nums[right]]++;

            while (freq.size() == totalDistinct) {
                // All subarrays starting from `left` to `right` and ending at `right` are valid.
                ans += n - right;

                // Try to shrink window from the left
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
        }

        return ans;
    }
};