class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> map(26);
        for(int i=0;i<26;++i){
            map[i]=i;
        }
        for(int i=0;i<s1.size();++i){
            //unite
            int x= find(s1[i]-'a',map),y=find(s2[i]-'a',map);
            if(x!=y){
                if(x<y)map[y]=x;
                else map[x]=y;
            }
        }
        string ret;
        for(char c:baseStr){
            ret+=(char)(find(c-'a',map)+'a');
        }
        return ret;
    }
    
    int find(int x,vector<int> & map){
        if(x==map[x])return x;
        return map[x]=find(map[x],map);
    }
};