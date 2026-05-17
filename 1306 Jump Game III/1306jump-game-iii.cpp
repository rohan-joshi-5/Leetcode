class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // 1. Boundary check and visited check
        if (start < 0 || start >= arr.size() || arr[start] < 0) {
            return false;
        }
        
        // 2. Success condition
        if (arr[start] == 0) {
            return true;
        }
        
        // 3. Mark as visited by making the value negative
        // (Saves space compared to using a separate 'visited' set)
        int jumpLength = arr[start];
        arr[start] = -arr[start];
        
        // 4. Recursively check right and left jumps
        return canReach(arr, start + jumpLength) || 
               canReach(arr, start - jumpLength);
    }
};