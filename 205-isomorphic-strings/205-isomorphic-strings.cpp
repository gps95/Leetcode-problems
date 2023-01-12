class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map;
        unordered_set<char> mapped;
        for(int i=0;i<s.size();++i){
            if(map.find(s[i])!=map.end()){//found
                if(map[s[i]]!=t[i]) return false;
            }
            else{//not found
                if(mapped.find(t[i])!=mapped.end())return false;
                map.insert({s[i],t[i]});
                mapped.insert(t[i]);
            }
        }
        return true;
    }
};