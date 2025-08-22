class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int low_x = INT_MAX, high_x = -1;
        int low_y = INT_MAX, high_y = -1;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                    low_x = min(low_x,i);
                    high_x = max(high_x,i);
                    low_y = min(low_y,j);
                    high_y = max(high_y,j);
                }
            }
        }
        return (high_x-low_x+1) * (high_y-low_y+1);
    }
};