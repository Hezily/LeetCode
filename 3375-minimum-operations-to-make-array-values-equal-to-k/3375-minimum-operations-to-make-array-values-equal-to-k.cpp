class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operations=0;
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        if(mini<k) return -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>k){
                operations++;
                while(i+1<nums.size() && nums[i]==nums[i+1])
                i++;
            }
        }
        return operations;
    }
};