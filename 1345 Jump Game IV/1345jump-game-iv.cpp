class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        // Base case: already at the last index
        if (n <= 1) return 0;

        // Step 1: Build the hash map for teleportation
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++) {
            graph[arr[i]].push_back(i);
        }

        // Step 2: Initialize BFS
        queue<int> q;
        q.push(0);
        
        vector<bool> visited(n, false);
        visited[0] = true;
        
        int steps = 0;

        // Step 3: Run BFS
        while (!q.empty()) {
            int size = q.size(); // Process level by level
            
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                // If we reached the end, return the steps taken
                if (curr == n - 1) return steps;

                // Move 1: Teleport to same values
                if (graph.count(arr[curr])) {
                    for (int next : graph[arr[curr]]) {
                        if (!visited[next]) {
                            visited[next] = true;
                            q.push(next);
                        }
                    }
                    // CRITICAL OPTIMIZATION: Clear the list to prevent redundant checks
                    graph.erase(arr[curr]);
                }

                // Move 2: Jump forward
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }

                // Move 3: Jump backward
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
            }
            steps++; // Increment steps after finishing a full level
        }
        
        return -1; // Should not reach here given valid inputs
    }
};