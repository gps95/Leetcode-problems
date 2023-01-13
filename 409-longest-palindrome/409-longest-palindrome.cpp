class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        int l=0;
        for(char c:s){
            map[c]++;
            if(map[c]==2){
                map.erase(c);
                l+=2;
            }
        }
        if(!map.empty())l++;
        return l;
    }
};