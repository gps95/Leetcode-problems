class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int depth=triangle.size()-2;
        while(depth>=0){
            for(int i=0;i<triangle[depth].size();++i){
            triangle[depth][i]+= min(triangle[depth+1][i],triangle[depth+1][i+1]);
            }
            depth--;
        }
        return triangle[0][0];
    }
};