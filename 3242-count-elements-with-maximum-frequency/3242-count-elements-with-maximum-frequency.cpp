class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> mpp(101,0);
        for(int i=0;i<n;i++){
            mpp[nums[i]]+= 1;
        }
        int maxFreq = *max_element(mpp.begin(),mpp.end());
        int ans = 0;
        for(int i=0;i<=100;i++){
            if(mpp[i] == maxFreq) ans+= mpp[i];
        }
        return ans;

    }
};