class Solution {
public:
    int maxFreqSum(const std::string &s) {
        std::vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a'] += 1;
        }

        int vMax = 0, cMax = 0;
        std::string vowels = "aeiou";

        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            int f = freq[i];

            if (vowels.find(c) != std::string::npos) {
                vMax = std::max(vMax, f);
            } else {
                cMax = std::max(cMax, f);
            }
        }

        return vMax + cMax;
    }
};