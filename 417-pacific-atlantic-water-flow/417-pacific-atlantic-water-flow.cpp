class Solution {
public:
    using vvi = vector<vector<int>>;
    using misi = unordered_map<int,unordered_set<int>>;
    using qii = queue<pair<int,int>>;
     vvi pacificAtlantic(vector<vector<int>>& heights) {
        vvi res;
        misi mpac,mat;
        qii qpac,qat;

        //fill queues and mark as visited
        for(int i=0;i<heights.size();++i)
            qpac.push({i,0}), mpac[i].insert(0),
            qat.push({i,heights[0].size()-1}), mat[i].insert(heights[0].size()-1);

        for(int j=0;j<heights[0].size()-1;++j)
            qpac.push({0,j+1}), mpac[0].insert(j+1),
            qat.push({heights.size()-1,j}),mat[heights.size()-1].insert(j);
        
        //bfs pacific
        bfs(heights,qpac,mpac,res,false,mat);
        //bfs atlantic
        bfs(heights,qat,mat,res,true,mpac);

        return res;
    }

    void bfs(vvi & heights,qii &q,misi &map,vvi &res,bool compare,misi & map2){
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;q.pop();
            int h = heights[i][j];
            if(compare && map2[i].find(j)!=map2[i].end())//compare with  first map
                res.push_back({{i,j}});

            //look for neighbouring cells that can be visited
            if(i>0 && map[i-1].find(j)==map[i-1].end() && h<=heights[i-1][j])
                q.push({i-1,j}),map[i-1].insert(j);
            if(j>0 && map[i].find(j-1)==map[i].end() && h<=heights[i][j-1])
                q.push({i,j-1}),map[i].insert(j-1);
            if(i<heights.size()-1 && map[i+1].find(j)==map[i+1].end() && h<=heights[i+1][j])
                q.push({i+1,j}),map[i+1].insert(j);
            if(j<heights[0].size()-1 && map[i].find(j+1)==map[i].end() && h<=heights[i][j+1])
                q.push({i,j+1}),map[i].insert(j+1);
        }
    }
};















