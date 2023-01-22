class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> current;
        aux(s,0,current,ret);
        return ret;
    }
private: 
    void aux(string& s, int pos, vector<string>& current, vector<vector<string>>& ret) {
        if (pos == s.length()) ret.push_back(current);
        else for (int i=pos;i<s.length();++i)
            if (isPalindrome(s,pos,i)) {
                current.push_back(s.substr(pos,i-pos+1));
                aux(s,i+1,current,ret);
                current.pop_back();
            }
    }
    
    bool isPalindrome(string& s, int l, int r) {
        while(l<r) if(s[l++]!=s[r--]) return false ;
        return true;
    }
};