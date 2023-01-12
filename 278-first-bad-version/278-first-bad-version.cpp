// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1) return 1;
        int ini=0,fin=n-1,mid;
        while(ini<=fin){
            mid = ini + (fin-ini)/2;
            if(isBadVersion(mid)){
                fin=mid-1;
            }
            else ini=mid+1;
        }
        return ini;
    }
};