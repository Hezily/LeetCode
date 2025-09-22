class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }

        int result = 0;
        // Sum frequencies equal to maxFreq
        for (auto& p : freq) {
            if (p.second == maxFreq) {
                result += p.second;
            }
        }

        return result;
    }
};