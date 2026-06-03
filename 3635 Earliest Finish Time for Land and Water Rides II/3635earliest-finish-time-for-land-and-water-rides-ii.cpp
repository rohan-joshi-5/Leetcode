class Solution {
public:
    int getEarliestFinish(const vector<int>& firstStart,
                          const vector<int>& firstDur,
                          const vector<int>& secondStart,
                          const vector<int>& secondDur) {

        // Step 1: Find the absolute earliest we can finish ANY ride in the
        // first category
        int minEndFirst = INT_MAX;
        for (int i = 0; i < firstStart.size(); i++) {
            minEndFirst = min(minEndFirst, firstStart[i] + firstDur[i]);
        }

        // Step 2: Use that optimal earliest finish time to find the best second
        // ride
        int earliestFinish = INT_MAX;
        for (int j = 0; j < secondStart.size(); j++) {
            // We either start right after the first ride finishes, or we have
            // to wait for this ride to open
            int startSecond = max(minEndFirst, secondStart[j]);
            earliestFinish = min(earliestFinish, startSecond + secondDur[j]);
        }

        return earliestFinish;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        return min(getEarliestFinish(landStartTime, landDuration,
                                     waterStartTime, waterDuration),
                   getEarliestFinish(waterStartTime, waterDuration,
                                     landStartTime, landDuration));
    }
};