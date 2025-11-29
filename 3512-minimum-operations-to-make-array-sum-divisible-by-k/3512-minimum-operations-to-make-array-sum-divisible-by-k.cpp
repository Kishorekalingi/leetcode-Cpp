class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(int it:nums){
            sum+=it;
        }
        return sum%k;
    }
};