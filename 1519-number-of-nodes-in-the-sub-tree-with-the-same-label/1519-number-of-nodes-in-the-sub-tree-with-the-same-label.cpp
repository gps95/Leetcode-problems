class Solution {
    using vi=vector<int>;
    using vb=vector<bool>;
    using vvi=vector<vector<int>>;
public:
    vi countSubTrees(int n,vvi & edges,string labels) {
        vi ret(n,0);
        vvi graph(n);
        for(auto vec:edges){
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        vi map(26,0);
        dfs(0,graph,ret,map,labels);
        return ret;
    }

    void dfs(int pos,vvi & graph,vi & ret,vi & map,string & labels){
        if(ret[pos]==0){
            ret[pos]=1;
            for(auto num:graph[pos]){
                vi map2(26,0);
                dfs(num,graph,ret,map2,labels);
                for(int i=0;i<26;++i) map[i]+=map2[i];
            }
            ret[pos]=++map[labels[pos]-'a'];
        }
    }
};