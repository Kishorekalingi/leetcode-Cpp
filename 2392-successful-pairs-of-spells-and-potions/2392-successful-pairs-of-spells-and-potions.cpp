class Solution {


public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> res(n,0);
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            long long minPos = (success + spells[i]-1)/spells[i];
            int ind = lower_bound(potions.begin(),potions.end(),minPos) - potions.begin();
            res[i] = m - ind;
        }
        return res;
    }
};