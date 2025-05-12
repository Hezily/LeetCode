class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        int count[10] = {0};

        // Count frequency of each digit
        for (int d : digits) {
            count[d]++;
        }

        // Try every 3-digit even number from 100 to 998
        for (int num = 100; num <= 998; num += 2) {
            int a = num / 100;         // Hundreds digit
            int b = (num / 10) % 10;   // Tens digit
            int c = num % 10;          // Units digit (even)

            // Temporary frequency array
            int tempCount[10];
            memcpy(tempCount, count, sizeof(count));

            // Check if we can use digits a, b, c
            if (tempCount[a] > 0) {
                tempCount[a]--;
                if (tempCount[b] > 0) {
                    tempCount[b]--;
                    if (tempCount[c] > 0) {
                        result.push_back(num);
                    }
                }
            }
        }

        return result;
    }
};
