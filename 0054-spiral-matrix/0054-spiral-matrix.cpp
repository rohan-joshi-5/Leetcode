class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int dir=0;
        /*
            dir=0 left to right
            dir=1 top to down
            dir=2 right to left
            dir=3 down to top
        */
        vector<int> result;
        int top=0,down=m-1;
        int left=0,right=n-1;
        while(top <= down && left <= right){
            if(dir==0){
                //left to right ;row(top) ermains constant
                for(int i=left;i<=right;i++){
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir==1){
                //top to down column(right) remains constant
                for(int i=top;i<=down;i++){
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            if(dir==2){
                //right to left row(down) remains constant
                for(int i=right;i>=left;i--){
                    result.push_back(matrix[down][i]);
                }
                down--;
            }
            if(dir==3){
                //down to top column(left) remains constant
                for(int i=down;i>=top;i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if(dir==4)  dir=0;
        }
        return result;
    }
};