class Solution {
public:
    int maxFreqSum(string s) {      
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a'] ++;
        }
        int vowelFreq = 0;
        int consonentFreq = 0;
        for(int i=0;i<26;i++){
            if(i == 0 || i == 4 || i== 8 || i == 14 || i == 20) vowelFreq = max(vowelFreq,freq[i]);
            else consonentFreq = max(consonentFreq,freq[i]);
        }
        return consonentFreq + vowelFreq;
    }
};