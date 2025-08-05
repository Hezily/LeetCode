class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        vector<bool> used(baskets.size(), false);

        for (int i = 0; i < fruits.size(); i++) {
            bool isPlaced = false;
            for (int j = 0; j < baskets.size(); j++) {
                if (fruits[i] <= baskets[j] && !used[j]) {
                    used[j] = true;
                    isPlaced = true;
                    break;
                }
            }
            if (!isPlaced) {
                unplaced++;
            }
        }

        return unplaced;
    }
};
