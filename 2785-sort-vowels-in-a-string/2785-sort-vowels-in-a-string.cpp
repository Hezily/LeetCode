class Solution {
public:

    bool checkVol(string s)
    {
        int arr[5] = {'A', 'E', 'I', 'O', 'U'};
        int size = s.size();
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(s[i] == arr[j])
                {
                    return true;
                }
            }
        }
        return false;
    }

    string sortVowels(string s) {
        int count = 0;
        if(checkVol(s))
        {
            count++;
        }
        return s;
    }
};