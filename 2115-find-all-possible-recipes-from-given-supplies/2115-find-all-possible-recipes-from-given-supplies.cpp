class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // return recipes;

        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> available(supplies.begin(), supplies.end());
        queue<string> q;

        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size();
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
            }
        }

        for (const string& item : supplies) {
            q.push(item);
        }

        vector<string> result;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (inDegree.find(curr) != inDegree.end()) {
                result.push_back(curr);
            }

            for (const string& next : graph[curr]) {
                if (--inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return result;
    }

};
