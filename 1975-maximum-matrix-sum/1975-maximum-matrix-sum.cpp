class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int size = matrix.size();
        long long sum = 0;
        int countNegative = 0;
        int smallestAbsoluteValue = INT_MAX;

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                sum += abs(matrix[i][j]);

                if(matrix[i][j] < 0)
                {
                    countNegative++;
                }

                smallestAbsoluteValue = min(smallestAbsoluteValue, abs(matrix[i][j]));
            }
        }

        if(countNegative % 2 == 0)
        {
            return sum;
        }

        return sum - 2 * smallestAbsoluteValue;
    }
};