class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m=n;
        int num=1;
        //n is already column
        int dir=0;
        /*
            dir=0 left to right
            dir=1 top to down
            dir=2 right to left
            dir=3 down to top
        */
        vector<vector<int>> result(n,vector<int>(n));
        int top=0,down=m-1;
        int left=0,right=n-1;
        while(top <= down && left <= right){
            if(dir==0){
                //left to right ;row(top) ermains constant
                for(int i=left;i<=right;i++){
                    result[top][i]=num++;
                }
                top++;
            }
            if(dir==1){
                //top to down column(right) remains constant
                for(int i=top;i<=down;i++){
                    result[i][right]=num++;
                }
                right--;
            }
            if(dir==2){
                //right to left row(down) remains constant
                for(int i=right;i>=left;i--){
                    result[down][i]=num++;
                }
                down--;
            }
            if(dir==3){
                //down to top column(left) remains constant
                for(int i=down;i>=top;i--){
                    result[i][left]=num++;
                }
                left++;
            }
            dir++;
            if(dir==4)  dir=0;
        }
        return result;
    }
};