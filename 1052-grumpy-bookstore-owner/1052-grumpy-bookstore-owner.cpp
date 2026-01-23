class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int size = customers.size();
        int sum = 0;
        for(int i = 0; i < size; i++)
        {
            if(grumpy[i] == 0)
            {
                sum += customers[i];
            }
        }

        int satisfied = 0, maxSatisfied = 0;

        for(int i = 0; i < minutes; i++)
        {
            if(grumpy[i] == 1)
            {
                satisfied += customers[i];
            }
        }
        maxSatisfied = satisfied;

        for(int i = minutes; i < size; i++)
        {
            if(grumpy[i] == 1)
            {
                satisfied += customers[i];
            }
            if(grumpy[i - minutes] == 1)
            {
                satisfied -= customers[i - minutes];
            }

            maxSatisfied = max(maxSatisfied, satisfied);
        }

        return sum + maxSatisfied;

    }
};