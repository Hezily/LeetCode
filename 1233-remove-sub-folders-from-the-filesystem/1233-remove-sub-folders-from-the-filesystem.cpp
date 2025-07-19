class Solution {
    struct trienode {
        bool wordEnd = false;
        unordered_map<string, trienode*> child;
    };
    
    // Insert folder into the Trie
    void trieInsert(const string& folder, trienode* curr) {
        int i = 1;
        while (i < folder.size()) {
            string name;
            while (i < folder.size() && folder[i] != '/') {//Extract folder name
                name.push_back(folder[i]);
                i++;
            }
            
            if (curr->wordEnd) return;  // Stop if a parent folder already exists
            
            if (!curr->child.count(name)) //Make a newnode if the path, already doesn't exist
                curr->child[name] = new trienode;
            curr = curr->child[name];
            i++;
        }
        curr->wordEnd = true;
    }

    // Traverse the Trie to collect results
    void searchTrie(trienode* curr, vector<string>& res, string path) {
        if (!curr) return;
        if (curr->wordEnd) {
            path.pop_back();        //Remove '/'
            res.push_back(path);    //Save path
            return;
        }

        for (auto& [name, child] : curr->child) {
            searchTrie(child, res, path + name + "/");
        }
    }
    
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        trienode* root = new trienode;

        // Insert all folders into the Trie
        for (const string& folder : folders) 
            trieInsert(folder, root);
        
        vector<string> res;//Stores result
        searchTrie(root, res, "/");
        return res;
    }
};