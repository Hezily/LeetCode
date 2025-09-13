class Solution {
public:

    // int checkSize(int n)
    // {
    //     int count = 0;
    //     while(n > 0)
    //     {
    //         count++;
    //         n = n / 10;
    //     }
    //     return count;
    // }

    // bool check(int n)
    // {
    //     while (n != 1) 
    //     {
    //         int size = checkSize(n);
    //         int i = 0;
    //         int sum = 0;

    //         while(i < size)
    //         {
    //             int digit = n % 10;   
    //             sum = sum + pow(digit, 2);
    //             n = n / 10;
    //             i++;
    //         }

    //         n = sum;
    //     }

    //     return true;
    // }

    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = getNext(n);

        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return fast == 1;
    }
};


