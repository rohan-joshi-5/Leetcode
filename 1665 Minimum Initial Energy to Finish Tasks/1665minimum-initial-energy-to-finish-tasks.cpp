class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort in descending order of the buffer (minimum - actual)
        sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int initialEnergy = 0;
        int currentEnergy = 0;

        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            // If current energy is less than the minimum required, top it up
            if (currentEnergy < minimum) {
                initialEnergy += (minimum - currentEnergy);
                currentEnergy = minimum; // We just added exactly enough to reach the minimum
            }

            // Perform the task
            currentEnergy -= actual;
        }

        return initialEnergy;
    }
};