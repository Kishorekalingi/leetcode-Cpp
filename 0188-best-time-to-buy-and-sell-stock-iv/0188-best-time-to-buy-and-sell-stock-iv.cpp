class Solution {
private:
    int fun(int i,vector<int>& prices,int cap,int b,vector<vector<vector<int>>>&dp){
        if(i==prices.size() || cap == 0) return 0;
        if(dp[i][b][cap] != -1) return dp[i][b][cap];
        int profit = 0;
        if(!b){
            profit = max(-prices[i] + fun(i+1,prices,cap,1,dp),fun(i+1,prices,cap,0,dp));
        }
        else{
            profit = max(prices[i] + fun(i+1,prices,cap-1,0,dp),fun(i+1,prices,cap,1,dp));
        }
        return dp[i][b][cap] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fun(0,prices,k,0,dp);
    }
};