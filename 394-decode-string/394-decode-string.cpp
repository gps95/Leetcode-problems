class Solution {
public:
    string decodeString(string s) {
        int pos=0;
        return decodeS(s,pos);
    }
    string decodeS(string &s,int &pos) {
        string ret;
        while(pos<s.size() && s[pos]!=']'){
            if(isdigit(s[pos])){
                int num = s[pos++]-'0';
                while(isdigit(s[pos]))
                    num= (num*10) + s[pos++]-'0';
                ++pos;//saltar el '['
                string dec = decodeS(s,pos);
                for(int i=0;i<num;++i) ret+=dec;
            }
            else if(isalpha(s[pos])) ret+=s[pos];
            pos++;
        }
        return ret;
    }
};