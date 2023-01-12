class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> sums;
        while(1){
            int sum=0;
            while(n){
                int digit=n%10;
                sum+=digit*digit;
                n/=10;
            }
            if(sum==1)return true;
            if(sums.find(sum)!=sums.end())return false;
            else sums.insert(sum);
            n=sum;
        }
        return false;
    }
};