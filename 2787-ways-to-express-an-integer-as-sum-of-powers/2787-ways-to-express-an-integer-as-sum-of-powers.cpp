class Solution {
    #define MOD 1000000007

    int binaryExponentiation(int a,int b){
        int res = 1;
        while(b){
            if(b&1)
                res *= a;
            a *= a;
            b /= 2;
        }
        return res;
    }
public:
    int numberOfWays(int n, int x) {
        // Step-1: Calculate powers array
        vector<int> powers;
        for(int i=1;i<=n;++i){
            int power = binaryExponentiation(i,x);
            if(power>n)//Can't include any more powers
                break;
            
            powers.push_back(power);
        }
        // Step-2: Apply Tabulation
        vector<int> dp(n+1);
        dp[0] = 1;
        int p = powers.size();
        for(int pos=1;pos<=p;++pos){
            for(int target=n;target>=powers[pos-1];--target){
                dp[target] = (dp[target] + dp[target-powers[pos-1]]) % MOD;
            }
        }
        return dp[n];
    }
};