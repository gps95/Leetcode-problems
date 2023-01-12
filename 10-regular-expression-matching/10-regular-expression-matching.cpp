class Solution {
public:
    bool isMatch(string s, string pattern) {
        if (pattern.empty())return s.empty();
        if (pattern[1]=='*')
            //char*:empty string or 1+ repetitions of char:[x*== {},{x},{xx},{xxx},...]
            //differentiate between case of empty string and otherwise
            //-empty string:remove char* from pattern
            //-otherwise: if s is not empty and pattern is valid:remove current char from s
            return (isMatch(s,pattern.substr(2)) ||//case empty string
            !s.empty() && (pattern[0]=='.' || pattern[0]==s[0]) && isMatch(s.substr(1),pattern));//otherwise
        else//normal case,we check that s is not empty or pattern is valid 
            return !s.empty() && (pattern[0]=='.' || pattern[0]==s[0]) && isMatch(s.substr(1), pattern.substr(1));
    }
};