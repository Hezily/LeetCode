class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);
        long long div = a / b;

        if ((dividend < 0) ^ (divisor < 0))
            return -div;

        return div;
    }
};
