class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        int row=0;
        while(row<numRows){
            vector<int> rowvec;
            for(int i=0;i<=row;++i){
                if(i==0 || i==row) rowvec.push_back(1);
                else rowvec.push_back(res[row-1][i]+res[row-1][i-1]);
            }
            res.push_back(rowvec);
            row++;
        }    

        return res;
    }
};