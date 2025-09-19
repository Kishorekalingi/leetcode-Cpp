class Solution {
public:
    int minDistance(string s, string s1) {
        if(s == s1) return 0;
        int n = s.size();
        int m = s1.size();
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == s1[j - 1])
                    cur[j] = 1 + prev[j - 1];
                else
                    cur[j] = max(prev[j], cur[j - 1]);
            }
            prev = cur;
        }

        int ans = prev[m];  
        return (n-ans) + (m - ans);
    }
};