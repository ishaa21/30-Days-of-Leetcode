class Solution {
public:
// int findUnique(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
//           if( i<0 || j<0 || grid[i][j]==1) return 0;
//           if(i==0 && j==0) return 1;
//           if(dp[i][j]!=-1) return dp[i][j];
//           int up=findUnique(grid,i-1,j,dp);
//           int left=findUnique(grid,i,j-1,dp);
//           return dp[i][j]=up+left;
// }
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
          int row=obstacleGrid.size();
          int col=obstacleGrid[0].size();
          vector<vector<int>>dp(row,vector<int>(col,-1));
         // int ans=findUnique(obstacleGrid,row-1,col-1,dp);
          for(int i=0;i<row;i++){
              for(int j=0;j<col;j++){
                  if(i==0 && j==0 && obstacleGrid[i][j]==0)  {
                      dp[i][j]=1;
                      continue;
                  } 
                  if(obstacleGrid[i][j]==1){
                     dp[i][j]=0;
                     continue;
                  } 
                  int up=0,left=0;
                  if(i>0) up=dp[i-1][j];
                  if(j>0) left=dp[i][j-1];
                  dp[i][j]=up+left;
              }
          }
          return dp[row-1][col-1];
    }
};