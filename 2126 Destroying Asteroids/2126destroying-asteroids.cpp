class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long currentMass = mass;
        sort(asteroids.begin(),asteroids.end());
        for(int ast:asteroids){
            if(currentMass >= ast){
                currentMass+=ast;
            }else{
                return false;
            }
        }
        return true;
    }
};