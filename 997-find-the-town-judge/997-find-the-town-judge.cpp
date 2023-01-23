class Solution {
    typedef struct {int trusting,trustedBy;}strv;
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<strv> graph(n,{0,0});
        for(auto vi:trust){
           graph[vi[1]-1].trustedBy++;
           graph[vi[0]-1].trusting++;
        }
        int candidates=0,pos=0;
        for(int i=0;i<graph.size();++i)
            if(graph[i].trusting==0 && graph[i].trustedBy==n-1){
                candidates++;pos=i;
            }
        if(candidates==1)return pos+1;
        return -1;
    }
};