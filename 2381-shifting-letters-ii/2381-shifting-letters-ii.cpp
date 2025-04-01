class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);
        
        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], dir = shift[2];
            int val = (dir == 1) ? 1 : -1;
            diff[start] += val;
            diff[end + 1] -= val;
        }
        
        int shiftAmount = 0;
        for (int i = 0; i < n; i++) {
            shiftAmount += diff[i];
            int newChar = (s[i] - 'a' + shiftAmount) % 26;
            if (newChar < 0) newChar += 26;  
            s[i] = 'a' + newChar;
        }
        
        return s;
    }
};
