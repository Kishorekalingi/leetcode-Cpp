class Solution {
public:
    int fun(int n, int k, vector<int>& nums) {
        vector<int> prev(k + 1, 0);
    // Base cases
        prev[0] = 1;
        if (nums[0] == 0 && k >= 0) prev[0] = 2; // Pick or not pick zero
        else if (nums[0] <= k) prev[nums[0]] = 1;

        for (int i = 1; i < n; i++) {
            vector<int> cur(k + 1, 0);
            for (int tar = 0; tar <= k; tar++) {
                int notPick = prev[tar];
                int pick = 0;
                if (nums[i] <= tar) pick = prev[tar - nums[i]];
                cur[tar] = notPick + pick;
            }
            prev = cur;
        }
        return prev[k];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n== 1 && nums[0] == 0 && target == 0) return 2;
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        if (totalSum < abs(target) || (totalSum + target) % 2) return 0;

        return fun(n, (totalSum + target) / 2, nums);
    }
};