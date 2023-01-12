class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> ret;
        int top=0,bot=m.size()-1;
        int l=0,r=m[0].size()-1;
        while(l<=r && top<=bot){
            //right
            for(int j=l;j<=r && l<=r && top<=bot;j++)ret.push_back(m[top][j]);
            top++;
            //down
            for(int i=top;i<=bot && l<=r && top<=bot;i++)ret.push_back(m[i][r]);
            r--;
            //left
            for(int i=r;i>=l && l<=r && top<=bot;i--)ret.push_back(m[bot][i]);
            bot--;
            //up
            for(int i=bot;i>=top && l<=r && top<=bot;i--)ret.push_back(m[i][l]);
            l++;
        }
        return ret;
    }
};