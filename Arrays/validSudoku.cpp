/**
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

**/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> row[9];
        set<char> col[9];
        set<char> squareSet[9];
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char val = board[i][j];
                if(val == '.'){
                    continue;
                }
                // Check for row & col duplicates
                if(row[i].count(val) || col[j].count(val)){ return false; }
                
                // Check for 3x3 blocks
                int index = (i/3)*3 + j/3;
                if(squareSet[index].count(val)){ return false; }
                
                row[i].insert(val);
                col[j].insert(val);
                squareSet[index].insert(val);
            }
        }
        return true;
    }
};