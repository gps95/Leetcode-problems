class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int maxi,int maxj){
        if(i<0 || j<0 || i>=maxi || j>=maxj || grid[i][j]=='0') return;
        
        grid[i][j]='0';
        
        dfs(grid,i-1,j,maxi,maxj);
        dfs(grid,i+1,j,maxi,maxj);
        dfs(grid,i,j-1,maxi,maxj);
        dfs(grid,i,j+1,maxi,maxj);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),islands=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(grid,i,j,m,n);
                }
        return islands;
    }
};