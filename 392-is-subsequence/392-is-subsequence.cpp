class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        for(int i=0;i<s.size();++i){
            bool found=false;
            while(j<t.size() && !found){
                if(s[i]==t[j]) found=true;
                ++j;
            }
            if(!found) return false;
        }
        return true;
    }
};