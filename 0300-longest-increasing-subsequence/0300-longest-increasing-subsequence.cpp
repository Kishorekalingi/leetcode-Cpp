class Solution {
private:
    int fun(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int notPick = fun(i+1,prev,nums,dp);
        int pick = 0;
        if(prev == -1 || nums[i] > nums[prev]) {
            pick =  1 + fun(i+1,i,nums,dp);
        }
        return dp[i][prev+1] = max(pick,notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1,0) , cur(n+1,0);
        for(int i = n-1;i>=0;i--){
            for(int p = i-1;p>=-1;p--){
                int notTake = next[p+1];
                int take = 0;
                if(p == -1 || nums[i] > nums[p]){
                    take = 1 + next[i+1];
                }
                cur[p+1] = max(notTake,take);
            }
            next = cur;
        }
        return cur[0];
    }
};