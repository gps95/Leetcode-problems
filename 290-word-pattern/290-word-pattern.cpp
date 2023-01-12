class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word;
        unordered_map<char,string> map;
        unordered_set<string> words;
        //get words
        int position=0;
        for(char c:s){
            if(c==' '){
                if(map.find(pattern[position])==map.end()){
                    if(words.find(word)!=words.end())return false;
                    map.insert({pattern[position],word});
                }
                else if(map[pattern[position]]!=word) return false;
                words.insert(word);
                word.clear();position++;
            }
            else word+=c;
        }
        if(map.find(pattern[position])==map.end()){
            if(words.find(word)!=words.end())return false;
            map.insert({pattern[position],word});
        }
        else if(map[pattern[position]]!=word) return false;
        if(position+1<pattern.size())return false;
        return true;
    }
};