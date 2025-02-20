
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n + 1, 0);
        int max_side = 0, prev = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j];
                if (matrix[i][j - 1] == '1') {
                    dp[j] = min({dp[j], dp[j - 1], prev}) + 1;
                    max_side = max(max_side, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp; // Store previous row's value
            }
        }

        return max_side * max_side;
    }
};
