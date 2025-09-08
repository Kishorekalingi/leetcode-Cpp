class Solution {
public:
    int coinChange(vector<int>& coins, int k) {
        int n = coins.size();
        vector<int> prev(k+1,0),cur(k+1,0);
        for(int i=0;i<=k;i++){
            if(i%coins[0] == 0) prev[i] = i / coins[0];
            else prev[i] = 1e9;
        }
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=k;tar++){
                int notPick = prev[tar];
                int pick  = 1e9;
                if(coins[i] <= tar) pick = 1 + cur[tar-coins[i]];
                cur[tar] = min(pick,notPick);
            }
            prev= cur;
        }
        int ans = prev[k];
        if(ans >= 1e9) return -1;
        return ans;
    }
};