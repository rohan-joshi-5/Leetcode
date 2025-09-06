//the approach is that we pick each number and check if that numbers twice is in the set or if the number is even we check if its half is present in the set if any one of the condition.is true we return true other wise we add all the numbers in the set (avoiding the duplicates); at the end if nothing is returned it means we havent found any solutionn
class Solution {
public:

    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>seen;
        for(int x:arr){
            if(seen.count(2*x)||(x%2==0 && seen.count(x/2))){
                return true;
            }
            seen.insert(x);
        }
        return false;
    }
};