class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
        int result = 0;
        
        for (auto& domino : dominoes) {
            // Normalize the domino by sorting the two elements
            int a = domino[0];
            int b = domino[1];
            if (a > b) {
                swap(a, b); // Ensure a <= b
            }
            int normalized = a * 10 + b; // Create a unique key for the normalized domino

            // If the domino has been seen before, add its count to the result
            if (count.find(normalized) != count.end()) {
                result += count[normalized];
            }
            count[normalized]++; // Increment the count for this normalized domino
        }
        
        return result;
    }
};