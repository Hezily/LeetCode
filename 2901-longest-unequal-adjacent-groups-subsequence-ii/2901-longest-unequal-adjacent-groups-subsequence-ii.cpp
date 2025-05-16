class Solution {
public:
    int hammingDistance(const string& a, const string& b) {
        int count = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            if (a[i] != b[i]) ++count;
        }
        return count;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = (int)words.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        // Build graph with subsequence order constraint: i < j
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (groups[i] != groups[j] &&
                    words[i].size() == words[j].size() &&
                    hammingDistance(words[i], words[j]) == 1) {
                    graph[i].push_back(j);
                    indegree[j]++;
                }
            }
        }

        // Topological DP (Kahn's algorithm)
        queue<int> q;
        vector<int> dp(n, 1);      // length of longest subsequence ending at i
        vector<int> parent(n, -1); // to reconstruct the subsequence

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : graph[u]) {
                if (dp[u] + 1 > dp[v]) {
                    dp[v] = dp[u] + 1;
                    parent[v] = u;
                }
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Find max length and reconstruct
        int maxLen = 0, endIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                endIndex = i;
            }
        }

        vector<string> result;
        while (endIndex != -1) {
            result.push_back(words[endIndex]);
            endIndex = parent[endIndex];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};