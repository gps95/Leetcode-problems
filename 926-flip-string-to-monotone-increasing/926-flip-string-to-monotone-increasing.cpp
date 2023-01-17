class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips=0;
        //we suppose case right window occupies all(all values should be one)
        for (char c : s) {
            if (c=='0')++flips;
        }
        int ret = flips;//#0s==flips when case all 1s
        //we increase left window(window of zeroes)
        //we save best window combination(less flips)
        for (char c : s) {
            if (c == '0') {
                ret = min(ret,--flips);//when 0, flips-1
            } else {
                ++flips;//flips counts ones
            }
        }
        return ret;
    }
};