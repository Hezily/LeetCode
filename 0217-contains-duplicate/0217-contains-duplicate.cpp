class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int> arr;
        int index = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            arr.push_back(nums[i]);
        }
        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1])
            {
                return true;
            }
        }
        return false;
    }
};