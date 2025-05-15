class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int prevGroup = -1;

        for (int i = 0; i < words.size(); ++i) {
            if (groups[i] != prevGroup) {
                result.push_back(words[i]);
                prevGroup = groups[i];
            }
        }

        return result;
    }
};
