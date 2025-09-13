class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case explicitly
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);
        long long div = a / b;

        // Determine sign
        if ((dividend < 0) ^ (divisor < 0))  // XOR: different signs
            return -div;

        return div;
    }
};
