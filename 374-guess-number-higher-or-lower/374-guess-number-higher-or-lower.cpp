/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int ini=0,fin=n,mid;
        while(ini<=fin){
            mid=ini+(fin-ini)/2;
            int g = guess(mid);
            if(!g) return mid;
            else if(g==1) ini=mid+1;
            else fin=mid-1;
        }
        return -1;
    }
};