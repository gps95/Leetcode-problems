class Solution {
    typedef struct {int amount;vector<string>nextstring;}mystr;
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest="";
        bool allequal=true;
        int i=0;
        while(i<strs[0].size()){
            char c=strs[0][i];
            for(int j=1;j<strs.size();++j)
                if(i==strs[j].size() || strs[j][i]!=c) return longest;
            longest+=c;i++;
        }
        return longest;
    }
};