class Solution {
public:
    int minOperations(string s) {
        sort(s.begin(),s.end());
        int cntA = count(s.begin(), s.end(), 'a');
        if(cntA == s.size())
            return 0;
        return (26 - (s[cntA]-'a'));
        
    }
};