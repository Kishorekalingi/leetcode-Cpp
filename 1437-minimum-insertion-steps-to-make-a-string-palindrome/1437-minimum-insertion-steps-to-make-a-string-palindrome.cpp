class Solution {
public:
    int minInsertions(string s) {
        string k = s;
        int n = s.size();
        reverse(s.begin(),s.end());
        vector<int> prev(n+1,0) , cur(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == k[j-1]) cur[j] = 1 + prev[j-1];
                else cur[j] = max(prev[j],cur[j-1]);
            }
            prev = cur;
        }
        return n - prev[n];
    }
};