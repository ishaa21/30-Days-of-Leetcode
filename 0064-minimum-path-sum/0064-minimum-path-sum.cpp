class Solution {
public:
// int findMinPath(vector<vector<int>>&grid,int i,int j, vector<vector<int>>&dp){
//       if(i==0 && j==0) return grid[i][j];
//       if(i<0 || j<0) return 1e9;
//       if(dp[i][j]!=-1) return dp[i][j];
//       int up=grid[i][j]+findMinPath(grid,i-1,j,dp);
//       int left=grid[i][j]+findMinPath(grid,i,j-1,dp);    
//       return dp[i][j]=min(up,left);
// }
    int minPathSum(vector<vector<int>>& grid) {
          int row=grid.size();
          int col=grid[0].size();
          vector<vector<int>>dp(row,vector<int>(col,-1));
          //int ans=findMinPath(grid,row-1,col-1,dp);
          for(int i=0;i<row;i++){
              for(int j=0;j<col;j++){
                  if(i==0 && j==0) {
                      dp[i][j]=grid[0][0];
                      continue;
                  }
                  int up=1e9,left=1e9;
                  if(i>0) up=dp[i-1][j]+grid[i][j];
                  if(j>0) left=dp[i][j-1]+grid[i][j];
                  dp[i][j]=min(up,left);
              }
          }
          return dp[row-1][col-1];
    }
};