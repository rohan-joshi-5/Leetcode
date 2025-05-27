#include <vector>
#include <numeric>

class Solution {
public:
    int differenceOfSums(int n, int m) {
        std::vector<int> num1, num2;
        for (int i = 1; i <= n; ++i) {
            if (i % m == 0)
                num1.push_back(i);  // divisible
            else
                num2.push_back(i);  // not divisible
        }
        int sum1 = std::accumulate(num1.begin(), num1.end(), 0);
        int sum2 = std::accumulate(num2.begin(), num2.end(), 0);
        return sum2 - sum1;
    }
};
