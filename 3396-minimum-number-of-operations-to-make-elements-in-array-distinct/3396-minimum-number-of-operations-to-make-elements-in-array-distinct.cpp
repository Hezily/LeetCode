class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        int i = 0;

        while (i < nums.size()) {
            unordered_set<int> seen;
            bool hasDuplicate = false;

            for (int j = i; j < nums.size(); ++j) {
                if (seen.count(nums[j])) {
                    hasDuplicate = true;
                    break;
                }
                seen.insert(nums[j]);
            }

            if (!hasDuplicate) break;

            i += 3;
            operations++;
        }

        return operations;
    }
};
