class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=n;
        if(flowerbed.size()==1 && flowerbed[0]==0){
            return true;
        }
        for(int i =0 ;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                if(i==0){
                    if(flowerbed[i+1]==0){
                        count--;
                        flowerbed[i] = 1;
                    }
                }
                else if(i==flowerbed.size()-1){
                    if(flowerbed[i-1]==0){
                        count--;
                        flowerbed[i] = 1;
                    }
                }
                else{
                    if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                        count--;
                        flowerbed[i] = 1;
                    }
                }
            }
            if(count <= 0) return true;
        }
        if(count <= 0) return true;
        return false;
    }
};