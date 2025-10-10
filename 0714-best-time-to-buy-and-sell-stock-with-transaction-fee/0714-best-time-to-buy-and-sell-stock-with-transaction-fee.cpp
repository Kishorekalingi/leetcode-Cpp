class Solution {
private:
    int fun(int i,int b,vector<int>& prices,int fee,vector<vector<int>>& dp){
        if(i >= prices.size()) return 0;
        if(dp[i][b] != -1)return dp[i][b];
        if(b == 0){
            dp[i][b] = max((-prices[i]-fee) +fun(i+1,1,prices,fee,dp),fun(i+1,0,prices,fee,dp));
        }
        else{
            dp[i][b] = max(prices[i]+fun(i+1,0,prices,fee,dp),fun(i+1,1,prices,fee,dp));
        }
        return dp[i][b];
    }
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return fun(0,0,prices,fee,dp);
    
    }
};