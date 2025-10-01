class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles; 
        int emptyWB = numBottles;

        while (emptyWB >= numExchange) {
            int newWB = emptyWB / numExchange;  
            result += newWB;
            emptyWB = newWB + (emptyWB % numExchange);
        }

        return result;
    }
};
