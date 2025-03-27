class Solution {
    int mooresVotingAlgo(vector<int>& nums){
        int majority_element = nums[0];
        int freq = 1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]!=majority_element)   freq--;
            else                            freq++;
            
            if(freq==0){
                majority_element = nums[i];
                freq = 1;
            }
        }
        return majority_element;
    }
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int majority_element = mooresVotingAlgo(nums);

        int max_freq = 0;
        for(int i=0;i<n;++i)
            if(nums[i]==majority_element)
                max_freq++;

        int prefix_count = 0;
        for(int i=0;i<n-1;++i){
            if(nums[i]==majority_element){
                prefix_count++;
                max_freq--;
            }
            if((prefix_count > (i+1)/2) and (max_freq > (n-i-1)/2))
                return i;
        }
        return -1;
    }
};