class Solution {
public:
    void makezero(vector<vector<int>>& matrix,int i,int j)
    {
        int k=i,l=j;
        for(int k=0;k<matrix.size();k++)
        {
            matrix[k][j]=0;
        }
        for(int l=0;l<matrix[0].size();l++)
        {
            matrix[i][l]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>> visited(rows,vector<int>(cols,1));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    visited[i][j]=0;
                }
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(visited[i][j]==0)
                {
                    makezero(matrix,i,j);
                }
            }
        }
    }
};