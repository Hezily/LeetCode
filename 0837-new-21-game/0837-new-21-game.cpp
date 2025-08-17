class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // If Alice never needs to stop or n is large enough to always win
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double windowSum = 1.0;  // sum of probabilities in the sliding window
        double result = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = windowSum / maxPts;

            if (i < k) {
                windowSum += dp[i]; // still can draw more numbers
            } else {
                result += dp[i];    // Alice stops here
            }

            if (i - maxPts >= 0) {
                windowSum -= dp[i - maxPts]; // slide the window
            }
        }

        return result;
    }
};
