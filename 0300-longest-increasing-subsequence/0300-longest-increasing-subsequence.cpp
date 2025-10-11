class Solution {
private:
    int fun(int ind,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(ind == nums.size()) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int notPick = fun(ind+1,prev,nums,dp);
        int pick = 0;
        if(prev == -1|| nums[ind] > nums[prev]){
            pick = 1 + fun(ind+1,ind,nums,dp);
        }
        return dp[ind][prev+1] = max(pick,notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fun(0,-1,nums,dp);
    }
};