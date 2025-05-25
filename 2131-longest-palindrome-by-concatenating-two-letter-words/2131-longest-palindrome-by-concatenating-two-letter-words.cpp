class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int freq[26][26];
        memset(freq,0,sizeof(freq));
        int palindrome_count = 0;
        int mid_count = 0;

        for(string word: words){
            int a = word[0]-'a';
            int b = word[1]-'a';
            if(freq[b][a]>0){
                palindrome_count += 4;
                freq[b][a]--;
                if(a==b)
                    mid_count--;
            }else{
                freq[a][b]++;
                if(a==b)
                    mid_count++;
            }
        }
        if(mid_count>0)
            palindrome_count += 2;
        return palindrome_count;
    }
};