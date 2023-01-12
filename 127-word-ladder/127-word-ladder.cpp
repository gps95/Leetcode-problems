class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int steps=1;
        unordered_set<string> set;
        for(string s:wordList)set.insert(s);
        if(set.find(endWord)==set.end())return 0;
        set.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int size=q.size();
            for(int k=0;k<size;++k){
                string s=q.front();
                q.pop();
                if(s==endWord) return steps;
                for(int i=0;i<s.size();++i){
                    string aux=s;
                    for(int j='a';j<='z';++j){
                        aux[i]=j;
                        if(set.find(aux)!=set.end()){
                            q.push(aux);
                            set.erase(aux);       
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};