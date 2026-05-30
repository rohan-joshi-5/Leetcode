class FenwickTree {
private:
    vector<int> tree;
    int n;
public:
    FenwickTree(int size) : n(size) {
        tree.assign(n + 1, 0);
    }
    
    // Updates the maximum value at index i
    void maximize(int i, int val) {
        if (i == 0) return; 
        while (i <= n) {
            tree[i] = max(tree[i], val);
            i += (i & -i);
        }
    }
    
    // Retrieves the maximum value in the range [1, i]
    int query(int i) {
        int res = 0;
        while (i > 0) {
            res = max(res, tree[i]);
            i -= (i & -i);
        }
        return res;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        // Step 1: Find the maximum x to size our tree
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        
        // Add a buffer to max_x for our sentinel value
        int tree_size = max_x + 5;
        FenwickTree bit(tree_size);
        
        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(tree_size); 
        
        // Step 2: Simulate all Type 1 queries to get the final state
        for (const auto& q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }
        
        // Initialize the Fenwick tree with all gaps in the final state
        auto it = obstacles.begin();
        int prev_obs = *it;
        ++it;
        while (it != obstacles.end()) {
            int curr_obs = *it;
            bit.maximize(curr_obs, curr_obs - prev_obs);
            prev_obs = curr_obs;
            ++it;
        }
        
        vector<bool> ans;
        
        // Step 3: Process queries in reverse
        for (int i = queries.size() - 1; i >= 0; --i) {
            int type = queries[i][0];
            int x = queries[i][1];
            
            if (type == 1) {
                // Type 1: Remove the obstacle at x
                auto pos = obstacles.find(x);
                auto prev_it = prev(pos);
                auto next_it = next(pos);
                
                int p = *prev_it;
                int n = *next_it;
                
                // Erase x, which merges the gap. The new gap ends at 'n'
                obstacles.erase(pos);
                bit.maximize(n, n - p);
            } else {
                // Type 2: Check if a block of size 'sz' fits
                int sz = queries[i][2];
                
                // Find the largest obstacle <= x
                auto next_it = obstacles.upper_bound(x);
                int p = *prev(next_it);
                
                // The max gap is either a fully formed gap ending at or before p,
                // or the incomplete gap between p and x.
                int max_gap = max(bit.query(p), x - p);
                ans.push_back(max_gap >= sz);
            }
        }
        
        // Step 4: Reverse the results back to chronological order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};