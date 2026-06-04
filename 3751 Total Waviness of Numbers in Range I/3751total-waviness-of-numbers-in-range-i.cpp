class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int totalWavinessSum = 0;
        
        for (int i = num1; i <= num2; i++) {
            int n = i;
            
            // Any number with fewer than 3 digits has a waviness of 0
            if (n < 100) continue; 
            
            // Extract the first two digits from the right
            int right = n % 10;
            n /= 10;
            int mid = n % 10;
            n /= 10;
            
            // Process the remaining digits
            while (n > 0) {
                int left = n % 10; // This is the "left" neighbor from our right-to-left perspective
                
                // Check for Peak
                if (mid > right && mid > left) {
                    totalWavinessSum++;
                } 
                // Check for Valley
                else if (mid < right && mid < left) {
                    totalWavinessSum++;
                }
                
                // Shift our 3-digit window to the left
                right = mid;
                mid = left;
                n /= 10;
            }
        }
        
        return totalWavinessSum;
    }
};