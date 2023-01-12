class Solution {
public:
    int mySqrt(int x) {
        long num=x;
        int ini=0,fin=x,mid;
        while(num*num>x){
            num= (num + x/num)/2;
        }
        return num;
    }
};