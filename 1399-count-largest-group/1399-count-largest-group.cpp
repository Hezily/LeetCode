class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> digitSumFreq;

        // Calculate the sum of digits for each number from 1 to n
        for (int i = 1; i <= n; ++i) {
            int sum = digitSum(i);
            digitSumFreq[sum]++;
        }

        // Find the maximum frequency (i.e., the largest group size)
        int maxSize = 0;
        for (auto& [sum, freq] : digitSumFreq) {
            maxSize = max(maxSize, freq);
        }

        // Count how many groups have the largest size
        int count = 0;
        for (auto& [sum, freq] : digitSumFreq) {
            if (freq == maxSize) count++;
        }

        return count;
    }

private:
    // Helper function to calculate sum of digits
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
