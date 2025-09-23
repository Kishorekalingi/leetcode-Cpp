class Solution {
private:
    int fun(int i, int j,string s,string t,vector<vector<int>>& dp){
        if(i < 0) return j+1;
        if(j < 0 ) return i+1;
        if(dp[i][j] != -1 ) return dp[i][j];
        if(s[i] == t[j]) return fun(i-1,j-1,s,t,dp);
        int del = 1 +fun(i-1,j,s,t,dp);
        int insert = 1 +fun(i,j-1,s,t,dp);
        int replace = 1 + fun(i-1,j-1,s,t,dp);
        return dp[i][j] = min({del,insert,replace});
    }
public:
    int minDistance(string s, string t) {
        int n = s.size() ,m = t.size();
        vector<int> prev(m+1,0) ,cur(m+1,0);

        
        for(int j=0;j<=m;j++){
            prev[j] = j;
        }
        for(int i=1;i<=n;i++){
            cur[0] = i;
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]) cur[j] = prev[j-1];
                else{
                    cur[j] = 1 + min({prev[j-1],prev[j],cur[j-1]});
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};