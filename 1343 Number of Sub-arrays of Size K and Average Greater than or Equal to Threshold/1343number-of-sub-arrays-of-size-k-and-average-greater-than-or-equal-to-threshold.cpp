//  2 2 2 2 5 5 5 8
//  i   k  
//      k
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int target = k*threshold;
        int windowSum=0;
        int count=0;

        for (int i=0;i<k;i++) {
            windowSum+=arr[i];
        }
        if (windowSum>=target) count++;
        for(int i=k;i<n;i++){
            windowSum+=arr[i]-arr[i-k];
            if(windowSum>=target) count++;
        }
        return count;
    }
};
