class Solution {
public:
    set<int> result; // store unique numbers

    void generateNumbers(vector<int>& digits, vector<bool>& used, vector<int>& curr) {
        if (curr.size() == 3) {
            if (curr[0] != 0 && curr[2] % 2 == 0) { // valid conditions
                int num = curr[0] * 100 + curr[1] * 10 + curr[2];
                result.insert(num);
            }
            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                curr.push_back(digits[i]);

                generateNumbers(digits, used, curr);

                curr.pop_back();
                used[i] = false;
            }
        }
    }

    int totalNumbers(vector<int>& digits) {
        vector<bool> used(digits.size(), false);
        vector<int> curr;
        result.clear();

        generateNumbers(digits, used, curr);

        return result.size();
    }
};


// class Solution {
// public:
//     int totalNumbers(vector<int>& digits) {
//         set<int> result; // store unique valid numbers
//         int n = digits.size();

//         for (int i = 0; i < n; i++) {         // hundreds place
//             for (int j = 0; j < n; j++) {     // tens place
//                 for (int k = 0; k < n; k++) { // units place
//                     if (i != j && j != k && i != k) { // distinct indices
//                         if (digits[i] != 0 && digits[k] % 2 == 0) {
//                             int num = digits[i] * 100 + digits[j] * 10 + digits[k];
//                             result.insert(num);
//                         }
//                     }
//                 }
//             }
//         }
//         return result.size();
//     }
// };