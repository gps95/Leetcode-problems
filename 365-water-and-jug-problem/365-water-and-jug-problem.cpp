class Solution {
public:
    bool canMeasureWater(int j1, int j2, int target) {
        if(j1+j2<target) return false;
        return target%gcd(j1,j2) == 0;
    }
};