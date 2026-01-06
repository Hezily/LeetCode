class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<int> v(size + 1, 0);

        for(int i : nums)
        {
           v[i] = 1;
        }

        for(int i = 0; i <= size; i++)
        {
            if(v[i] == 0)
            {
                return i;
            }
        }

        return -1;
    }
};