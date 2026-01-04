// class Solution {
// public:

//     int findDivisor(int num)
//     {
//         int divisor = 0;
//         int sum = 0;

//         for(int fact = 1; fact < sqrt(num); fact++)
//         {
//             if(num % fact == 0)
//             {
//                 int other = num / fact;

//                 if(other == fact)
//                 {
//                     divisor += 1;
//                     sum += fact;
//                 }
//                 else
//                 {
//                     divisor += 2;
//                     sum += (fact + other);
//                 }
//             }
//         }

//         if(divisor > 4)
//         {
//             return 0;
//         }

//         return divisor == 4 ? sum : 0;
//     }

//     int sumFourDivisors(vector<int>& nums) {
//         int res = 0;

//         for(int &num : nums)
//         {
//             res += findDivisor(num);
//         }

//         return res;
//     }
// };

class Solution {
public:
    int sumIfFourDivisors(int num) {
        int divisors = 0;
        int sum = 0;

        for (int div = 1; div * div <= num; div++) {
            if (num % div == 0) {
                int other = num / div;

                if (div == other) {
                    divisors++;
                    sum += div;
                } else {
                    divisors += 2;
                    sum += (div + other);
                }
            }

            if (divisors > 4) {
                return 0;
            }
        }

        return divisors == 4 ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for (int &num : nums) {
            result += sumIfFourDivisors(num);
        }

        return result;
    }
};