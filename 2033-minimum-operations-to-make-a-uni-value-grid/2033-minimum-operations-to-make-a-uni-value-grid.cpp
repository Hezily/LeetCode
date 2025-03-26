class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> array;
        int remainder = grid[0][0]%x;

        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]%x != remainder)
                    return -1;
                array.push_back(grid[i][j]);
            }
        }
        sort(array.begin(),array.end());
        int n = array.size();
        int median = n/2;
        
        int steps = 0;
        for(int i=0;i<n;++i)
            steps += abs(array[i]-array[median])/x;

        return steps;
    }
};