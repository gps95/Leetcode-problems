class Solution {
public:
    bool detectCapitalUse(string word) {
        int nchanges=0;
        bool prevlower=islower(word[0]);
        bool curlower;
        for(int i=1;i<word.size();++i){
            curlower=islower(word[i]);
            if(prevlower!=curlower)nchanges++;
            prevlower=curlower;
        }
        return nchanges==0 || (nchanges==1 && isupper(word[0]) && islower(word[1]));
    }
};