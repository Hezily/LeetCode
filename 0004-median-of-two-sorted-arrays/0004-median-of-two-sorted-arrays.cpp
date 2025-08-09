class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1 + size2;

        vector<int> nums(size);

        int index1 = 0;
        int index2 = 0;
        int index = 0;

        while(index1 < size1 && index2 < size2)
        {
            if(nums1[index1] < nums2[index2])
            {
                nums[index] = nums1[index1];
                index1++;
                index++;
            }
            else
            {
                nums[index] = nums2[index2];
                index2++;
                index++;
            }
        }

        while(index1 < size1)
        {
            nums[index] = nums1[index1];
            index1++;
            index++;
        }
        while(index2 < size2)
        {
            nums[index] = nums2[index2];
            index2++;
            index++;
        }

        if(size % 2 == 1){
            return nums[size/2];
        }
        else {
             return (nums[size/2] + nums[(size/2) - 1]) / 2.0;
        }
    }
};