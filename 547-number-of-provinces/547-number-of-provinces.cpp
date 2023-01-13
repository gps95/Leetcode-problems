class Solution {
public:
    int findCircleNum(vector<vector<int>>& grid) {
        int islands=0;
        vector<bool> visited(grid.size(),false);
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j)
                if(grid[i][j] && !visited[i])
                    islands++,dfs(grid,i,visited);
        return islands;
    }

    void dfs(vector<vector<int>>& grid,int i,vector<bool> &visited){
        visited[i]=true;
        for(int j=0;j<grid[0].size();++j){
            if(grid[i][j] && !visited[j])
                dfs(grid,j,visited);
        }
    }
};