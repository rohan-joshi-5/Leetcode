class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        set<pair<int,int>> obs;
        for(auto &o : obstacles){
            obs.insert({o[0], o[1]});
        }

        int x = 0, y = 0;
        int d = 0; // 0=N, 1=E, 2=S, 3=W

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        int maxi = 0;

        for(int cmd : commands){
            if(cmd == -1){
                d = (d + 1) % 4; // turn right
            }
            else if(cmd == -2){
                d = (d + 3) % 4; // turn left
            }
            else{
                for(int i = 0; i < cmd; i++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if(obs.count({nx, ny})) break;

                    x = nx;
                    y = ny;

                    maxi = max(maxi, x*x + y*y);
                }
            }
        }

        return maxi;
    }
};