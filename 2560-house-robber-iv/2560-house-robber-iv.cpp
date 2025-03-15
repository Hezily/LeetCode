#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int start = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());
        int ans = 0;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isRobberyPossible(mid, nums, k)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
    
    bool isRobberyPossible(int capability, const vector<int>& nums, int minHouses) {
        int housesRobbed = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] <= capability) {
                housesRobbed++;
                i++;
            }
            if (housesRobbed >= minHouses) return true;
        }
        return false;
    }
};
