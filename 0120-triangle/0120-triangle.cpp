class Solution {
private: 
    int fun(int m,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if((m == 0) && (n == 0)) return triangle[0][0];
        if((m < 0 ) || (n < 0) || (n >= triangle[m].size())) return INT_MAX;
        if(dp[m][n] != -1 ) return dp[m][n];
        int up = fun(m-1,n,triangle,dp);
        int upleft = fun(m-1,n-1,triangle,dp);
        return dp[m][n] = triangle[m][n] + min(up,upleft);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m);
        for (int i = 0; i < m; ++i)
            dp[i] = vector<int>(triangle[i].size(), -1);
        int ans = INT_MAX;
        for(int i=0;i< triangle[m-1].size();i++){
            ans = min(ans,fun(m-1,i,triangle,dp));
        }
        return ans;
    }
};