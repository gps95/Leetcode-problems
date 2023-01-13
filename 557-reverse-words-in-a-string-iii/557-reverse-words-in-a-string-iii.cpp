class Solution {
public:
    string reverseWords(string s) {
        int i=0,j;
        for(j=0;j<=s.size();++j){
            if(s[j]==' ' || j==s.size()){
                reverse(&s[i],&s[j]);
                i=j+1;
            }
        }
        return s;
    }
};