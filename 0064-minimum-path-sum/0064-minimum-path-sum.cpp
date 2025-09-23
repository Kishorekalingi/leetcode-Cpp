class Solution {
private:
    int fun(int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if( n <0 || m <0) return INT_MAX;
        if(n == 0 && m == 0){
            return grid[0][0];
        }
        if(dp[n][m] != -1) return dp[n][m];
        int up = fun(n-1,m,grid,dp);
        int left = fun(n,m-1,grid,dp);
        return dp[n][m] = grid[n][m] + min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(n-1,m-1,grid,dp);
    }
};