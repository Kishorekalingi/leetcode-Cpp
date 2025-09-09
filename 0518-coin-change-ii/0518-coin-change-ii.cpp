class Solution {
private:
    int fun(int i,int k,vector<int>& coins,vector<vector<int>>& dp){
        if(i == 0){
            if(k % coins[0] == 0) return 1;
            return 0;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int notPick = fun(i-1,k,coins,dp);
        int pick = 0;
        if(coins[i] <= k) pick =fun(i,k-coins[i],coins,dp);
        return dp[i][k] = pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return fun(n-1,amount,coins,dp);
    }
};