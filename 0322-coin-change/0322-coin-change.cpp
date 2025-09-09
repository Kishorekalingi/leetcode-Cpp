class Solution {
private:
    int fun(int i,int k,vector<int>& coins,vector<vector<int>>& dp){
        if(i == 0){
            if(k % coins[0]== 0) return k /coins[0];
            return 1e9;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int notPick = fun(i-1,k,coins,dp);
        int pick = 1e9;
        if(coins[i] <= k) pick = 1 + fun(i,k-coins[i],coins,dp);
        return dp[i][k] = min(pick,notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = fun(n-1,amount,coins,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};