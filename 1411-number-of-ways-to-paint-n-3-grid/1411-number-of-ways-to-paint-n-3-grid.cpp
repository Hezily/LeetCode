class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<int>> t;
    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};

    int sol(int n, int prev)
    {
        if(n == 0)
        {
            return 1;
        }

        int res = 0;
        string last = states[prev];

        for(int curr = 0; curr < 12; curr++)
        {
            if(curr == prev)
            {
                continue;
            }

            if(t[n][prev] != -1)
            {
                return t[n][prev];
            }

            string currpat = states[curr];
            bool conflict = false;
            for(int col = 0; col < 3; col++)
            {
                if(currpat[col] == last[col])
                {
                    conflict = true;
                    break;
                }
            }

            if(!conflict)
            {
                res = (res + sol(n - 1, curr)) % M;
            }
        }
        return t[n][prev] = res;
    }

    int numOfWays(int n) {
        t.resize(n, vector<int>(12, -1)); 
        int res = 0;

        for(int i = 0; i < 12; i++)
        {
            res = (res + sol(n - 1, i)) % M;
        }
        return res;
    }
};
