class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Priority queue stores: {gain, pass, total}
        priority_queue<vector<double>> pq;

        // Push initial values into the heap
        for (auto &c : classes) { // O(n)
            int pass = c[0];
            int total = c[1];
            double gain = gainA(pass, total);

            pq.push({gain, (double)pass, (double)total});
        }

        // Assign extra students
        for (int s = 0; s < extraStudents; s++) { // O(m log n)
            auto top = pq.top();
            pq.pop();

            int pass = (int)top[1] + 1;
            int total = (int)top[2] + 1;
            double gain = gainA(pass, total);

            pq.push({gain, (double)pass, (double)total});
        }

        // Compute the final result
        double result = 0.0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            result += top[1] / top[2];
        }

        return result / classes.size();
    }

private:
    double gainA(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }
};