class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // int freq[1001] = {0}; 

        // for (int num : nums) {
        //     freq[num]++;
        // }

        // for (int i = 0; i <= 1000; i++) {
        //     if (freq[i] % 2 != 0) {
        //         return false;
        //     }
        // }

        // return true;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i += 2){
            if(nums[i] != nums[i+1]){
                return false;
            }
        }
        return true;
    }
};
