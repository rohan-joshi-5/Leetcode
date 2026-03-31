class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int prevTime = 0;

        for (string log : logs) {
            int id, time;
            string type;

            // parse log
            int p1 = log.find(':');
            int p2 = log.find(':', p1 + 1);

            id = stoi(log.substr(0, p1));
            type = log.substr(p1 + 1, p2 - p1 - 1);
            time = stoi(log.substr(p2 + 1));

            if (type == "start") {
                if (!st.empty()) {
                    res[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time;
            } 
            else { // "end"
                res[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }

        return res;
    }
};