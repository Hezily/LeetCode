class Solution {
public:
    bool isPowerOfTwo(long long n) {
        if (n <= 0) return false;
        long long val = 1;
        while (val < n) {
            if (val > LLONG_MAX / 2) break; // Prevent overflow
            val *= 2;
        }
        return val == n;
    }
};
