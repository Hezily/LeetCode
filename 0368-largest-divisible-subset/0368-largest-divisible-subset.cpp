class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        sort(nums.begin(),nums.end());
        int lis = 1;
        vector<int> dp(n+1,1);
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                    if(lis<dp[i])
                        lis = dp[i];
                }
            }
        }
        int prev = -1;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==lis &&  (prev%nums[i]==0 || prev==-1)){
                ans.push_back(nums[i]);
                lis -=1;
                prev = nums[i];
            }
        }
        return ans;
    }
};