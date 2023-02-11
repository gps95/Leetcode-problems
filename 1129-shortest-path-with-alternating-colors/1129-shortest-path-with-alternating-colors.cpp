class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redE, vector<vector<int>>& blueE) {
        vector<int> ret(n,-1);ret[0]=0;
        //expand graph:nodes [0,n-1] are red nodes and [n,2n-1] are blue nodes
        vector<vector<int>> graph(2*n);
        for(int i=0;i<redE.size() || i<blueE.size();++i){
            if(i<redE.size()) graph[redE[i][0]].push_back(redE[i][1]+n);
            if(i<blueE.size()) graph[blueE[i][0]+n].push_back(blueE[i][1]);
        }
        //normal bfs starting with red node 0 and blue node 0
        //in our expanded graph,these are nodes 0 and n
        vector<bool> visited(2*n,false); visited[0]=visited[n]=true;
        queue<int> q;q.push(0);q.push(n);
        int steps=1,nnodes=2;
        bool b=false;
        while(!q.empty()){
            int num=q.front();q.pop();
            if(--nnodes==0) b=true;
            for(int i:graph[num]){
                int aux=(i>=n)?n:0;
                if(!visited[i]){
                    visited[i]=true;
                    ret[i-aux]=(ret[i-aux]==-1)?steps:min(ret[i-aux],steps);
                    q.push(i);
                }
            }
            if(b){
                b=false;
                nnodes=q.size();
                steps++;
            }
        }
        return ret;
    }
};