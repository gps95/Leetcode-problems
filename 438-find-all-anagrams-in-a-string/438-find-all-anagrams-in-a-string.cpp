class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())return {};
        vector<int> freqP(26,0),window(26,0),ret;

        //initialize window
        for(int i=0;i<p.size();++i){//string[i]-'a' gets pos of char in vector
            freqP[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        if(freqP==window)ret.push_back(0);//check first pos,vector comparison is O(26)=>O(1)
        //advance
        for(int i=p.size();i<s.size();++i){
            window[s[i-p.size()]-'a']--;
            window[s[i]-'a']++;
            if(freqP==window)ret.push_back(i-p.size()+1);
        }
        return ret;
    }
};