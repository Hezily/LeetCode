class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long start = *min_element(ranks.begin(), ranks.end());
        long long end = *max_element(ranks.begin(), ranks.end());
        end = end * 1LL * cars * cars;
        long long ans = 0;

        while (start <= end) {
            long long mid = start + (end - start) / 2;
            if (isCarsRepaired(mid, ranks, cars)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }

private:
    bool isCarsRepaired(long long time, vector<int>& ranks, int carsToBeRepaired) {
        long long carsRepaired = 0;
        for (int rank : ranks) {
            carsRepaired += sqrt(time / rank);
            if (carsRepaired >= carsToBeRepaired) return true;
        }
        return false;
    }
};