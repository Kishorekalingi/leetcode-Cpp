class Solution {
public:
    int countPrimes(int n) {
        vector<bool> seve(n+1,true);
        seve[0]=seve[1]=false;
        int cnt=0;
        for(long i=2;i<n;i++){
            if(seve[i])cnt++;
            for(long j=i*i;j<n;j=j+i){
                seve[j]=false;
            }
        }
        return cnt;
    }
};