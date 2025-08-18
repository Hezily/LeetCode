// class Solution {
// public:
//     bool judgePoint24(vector<int>& cards) {
//         bool ans;
//         int size = cards.size();
//         sort(cards.begin(), cards.end());
//         for(int i = 0; i < cards.size(); i++)
//         {
//             if((abs(cards[size - 2] * cards[size - 1]) >= 24))
//             {
//                 ans = true;
//             }
//             else if(abs((cards[0] + cards[1]) * (cards[2] + cards[3])) >= 24)
//             {
//                 ans = true;
//             }
//             else
//             {
//                 ans = false;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
    
    bool solve(vector<double> nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24) < 1e-6; // check close to 24
        }
        
        // try all pairs
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                
                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }
                
                // try all operations
                for (double val : compute(nums[i], nums[j])) {
                    next.push_back(val);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
    
    vector<double> compute(double a, double b) {
        vector<double> res;
        res.push_back(a + b);
        res.push_back(a - b);
        res.push_back(b - a);
        res.push_back(a * b);
        if (fabs(b) > 1e-6) res.push_back(a / b);
        if (fabs(a) > 1e-6) res.push_back(b / a);
        return res;
    }
};
