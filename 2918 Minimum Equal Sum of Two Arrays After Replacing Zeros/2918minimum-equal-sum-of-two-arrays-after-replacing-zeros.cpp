class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zero1 = 0, zero2 = 0;
        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == 0) {
                zero1++;
            }
            sum1 = nums1[i] + sum1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] == 0) {
                zero2++;
            }
            sum2 = nums2[i] + sum2;
        }
        sum1 += zero1;
        sum2 += zero2;

        // If sums are already equal after replacing zeros with 1s
        if (sum1 == sum2) {
            return sum1;
        }

        // If sum1 is smaller, we need to increase it to match sum2
        if (sum1 < sum2) {
            if (zero1 > 0) {
                return sum2;
            } else {
                return -1; // No way to increase sum1
            }
        }

        // If sum2 is smaller, we need to increase it to match sum1
        if (zero2 > 0) {
            return sum1;
        } else {
            return -1; // No way to increase sum2
        }
    }
};