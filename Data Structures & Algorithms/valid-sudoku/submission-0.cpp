class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> square(9);

        for ( int i = 0; i < board.size(); ++i ) {
            for ( int j = 0; j < board[0].size(); ++j ) {
                if ( board[i][j] == '.' )
                    continue;
                
                if ( rows[i].count(board[i][j]) > 0 ) return false;
                else rows[i].insert(board[i][j]);
                
                if ( cols[j].count(board[i][j]) > 0 ) return false;
                else cols[j].insert(board[i][j]);

                int index = (i / 3) * 3 + (j / 3);
                if ( square[index].count(board[i][j]) > 0 ) return false;
                else square[index].insert(board[i][j]);
            }
        }

        return true;
    }
};
