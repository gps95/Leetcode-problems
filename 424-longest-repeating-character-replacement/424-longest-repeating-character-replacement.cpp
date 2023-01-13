class Solution {
public:
    int characterReplacement(string s, int k) {//sliding window
        int ini=0,maxC=0,maxL=0;
        vector<int> count(26,0);//counts occurences of chars
        for(int fin=0;fin<s.size();fin++){
            maxC = max(maxC,++count[s[fin]-'A']);
            //fin-ini+1-maxC == # of chars that are not current selected char
            if(fin-ini+1-maxC>k){//ini++ reduces window(we couldnt replace all)
                count[s[ini++]-'A']--;
            }
            maxL = max(maxL,fin-ini+1);
        }
        return maxL;
    }
};