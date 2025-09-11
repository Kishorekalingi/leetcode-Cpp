class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        using ull = unsigned long long;
        vector<ull> prev(amount + 1, 0), cur(amount + 1, 0);

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) prev[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int tar = 0; tar <= amount; tar++) {
                ull notPick = prev[tar];
                ull pick = (coins[i] <= tar) ? cur[tar - coins[i]] : 0;
                cur[tar] = pick + notPick;
            }
            prev = cur;
        }

        return static_cast<int>(prev[amount]); // Safe cast if within int range
    }
};