class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> v;

    //     for(int i = 0; i < nums.size(); i++)
    //     {
    //         for(int j = i + 1; j < nums.size(); j++)
    //         {
    //             if(nums[i] + nums[j] == target)
    //             {
    //                 v.push_back(i);
    //                 v.push_back(j);
    //             }
    //         }
    //     }
    //     return v;
    // }

    map<int, int> mp;

    for(int i = 0; i < nums.size(); i++)
    {
        int need = target - nums[i];

        if(mp.find(need) != mp.end())
        {
            return {mp[need], i};
        }

        mp[nums[i]] = i;
    }

    return {-1, -1};
    }
};
