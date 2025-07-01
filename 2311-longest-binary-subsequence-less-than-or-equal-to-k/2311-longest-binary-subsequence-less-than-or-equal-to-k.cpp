class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        //Step-1: Keep all set bits until value exceeds k
        long long val = 0;
        int i=0;
        while(i<min(n,32)){
            if(s[n-i-1]=='1'){
                long long power = pow(2,i);
                if(val + power > k)
                    break;
                val += power;
            }
            i++;
        }
        //Step-2: Count the removed bits
        int removed_count = 0;
        while(i<n){
            if(s[n-i-1]=='1')
                removed_count++;
            i++;
        }
        return n-removed_count;
    }
};