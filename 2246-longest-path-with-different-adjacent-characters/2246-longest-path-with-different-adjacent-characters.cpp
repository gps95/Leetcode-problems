class Solution {
    typedef struct mystr{
        vector<int> vec;
        char c;
        mystr(){vec=vector<int>();};
    }mystr;
public:
    int longestPath(vector<int>& parent, string s) {
        vector<mystr> graph(parent.size());
        graph[0].c=s[0];
        for(int i=1;i<parent.size();++i){
            graph[parent[i]].vec.push_back(i);
            graph[i].c=s[i];
        }
        int maxplen=1;
        dfs(0,graph,maxplen);
        return maxplen;
    }
    
    int dfs(int pos,vector<mystr> & graph,int & maxplen){
        int best1=0,best2=0;
        for(int num:graph[pos].vec){
            int aux=dfs(num,graph,maxplen);
            if(graph[pos].c!=graph[num].c){
                if(aux>best1){
                    best2=best1;
                    best1=aux;
                }
                else if(aux>best2) best2=aux;
            }
            
        }
        maxplen=max(maxplen,1+best1+best2);
        return best1+1;
    }
};