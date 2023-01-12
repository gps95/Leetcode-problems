class Solution {
public:    
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9),boxes(9);
        
        for(int i=0;i<9;++i)
            for(int j=0;j<9;++j)
                if(board[i][j]!='.'){
                    if(rows[i].find(board[i][j])!=rows[i].end()) return false;
                    if(cols[j].find(board[i][j])!=cols[j].end()) return false;
                    int box = (i/3)+((j/3)*3);
                    if(boxes[box].find(board[i][j])!=boxes[box].end()) return false;
                    
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    boxes[box].insert(board[i][j]);
                }
    return true;
    }
};