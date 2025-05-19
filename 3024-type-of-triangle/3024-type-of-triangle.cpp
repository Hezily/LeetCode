class Solution {
public:
    string triangleType(vector<int>& nums) {
        // Sort the sides to simplify triangle inequality check
        sort(nums.begin(), nums.end());

        // Check if it can form a triangle
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }

        // Check for equilateral triangle
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }

        // Check for isosceles triangle
        if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
            return "isosceles";
        }

        // Else it's a scalene triangle
        return "scalene";
    }
};
