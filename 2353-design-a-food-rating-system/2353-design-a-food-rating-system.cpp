
class FoodRatings {
private:
    struct Food {
        string name;
        int rating;
        Food(string n, int r) : name(n), rating(r) {}
    };

    struct Compare {
        bool operator()(const Food& a, const Food& b) const {
            if (a.rating != b.rating)
                return a.rating < b.rating;  // higher rating first
            return a.name > b.name;          // lexicographically smaller first
        }
    };

    unordered_map<string, priority_queue<Food, vector<Food>, Compare>> cuisinePQ;
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodToCuisine[food] = cuisine;
            foodToRating[food] = rating;

            cuisinePQ[cuisine].push(Food(food, rating));
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        foodToRating[food] = newRating;
        cuisinePQ[cuisine].push(Food(food, newRating));
    }

    string highestRated(string cuisine) {
        auto& pq = cuisinePQ[cuisine];
        while (true) {
            Food top = pq.top();
            if (top.rating == foodToRating[top.name]) {
                return top.name;
            }
            pq.pop();
        }
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */