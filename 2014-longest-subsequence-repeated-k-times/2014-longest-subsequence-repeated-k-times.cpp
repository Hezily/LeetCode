class Solution {
public:
    bool ifexists(string& s,string& p,int k){
        string str = "";
        while(k--) str+= p;
        int j = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]==str[j]){
                j++;
            }
            if(j==str.size()) break;
        }
        return j==str.size();
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        vector<int> freq(26);
        for(auto c : s) freq[c-'a']++;

        for(int i=0;i<26;i++){
            if(freq[i]<k){
                freq[i] = 0;
            }
            else{
                freq[i] /= k;
            }
        }
        queue<string> q;
        q.push("");
        string ans;
        while(!q.empty()){
            string str = q.front(); q.pop();
            vector<int> n_freq = freq;
            for(auto x : str){
                n_freq[x-'a']--;
            }
            for(int i=25;i>=0;i--){
                if(n_freq[i]==0) continue;
                char c = i + 'a';
                string temp = str + c;
                if(ifexists(s,temp,k)){
                    q.push(temp); // try to append with more elements
                    if(temp.size()>ans.size()){
                        ans = temp;
                    }
                }
            }
        } // O(L!*n) L<=7 ,L! = 128
        return ans;
    }
};