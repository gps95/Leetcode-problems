class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> map;
        for(char c:magazine)map[c]++;
        for(char c: ransomNote){
            if(map.empty() || map.find(c)==map.end())return false;
            if(--map[c]<=0)map.erase(c);
        }    
        return true;
    }
};