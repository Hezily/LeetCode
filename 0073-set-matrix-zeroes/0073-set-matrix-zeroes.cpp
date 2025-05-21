class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        //Find if 0th row and 0th col have to be set as all 0s
        bool zero_row = false;
        bool zero_col = false;
        for(int i=0;i<m;++i){
            if(matrix[i][0]==0){
                zero_row = true;
                break;
            }
        }
        for(int i=0;i<n;++i){
            if(matrix[0][i]==0){
                zero_col = true;
                break;
            }
        }

        //Mark row & col 0-th idx
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j)
                if(matrix[i][j]==0)
                    matrix[i][0] = matrix[0][j] = 0;
        }
        //Mark 0 rows
        for(int i=1;i<m;++i){
            if(matrix[i][0]==0){
                for(int j=1;j<n;++j)
                    matrix[i][j]=0;
            }
        }
        //Mark 0 cols
        for(int i=1;i<n;++i){
            if(matrix[0][i]==0){
                for(int j=1;j<m;++j)
                    matrix[j][i]=0;
            }
        }
        if(zero_row){
            for(int i=0;i<m;++i)
                matrix[i][0]=0;
        }
        if(zero_col){
            for(int j=0;j<n;++j)
                matrix[0][j]=0;
        }
    }
};