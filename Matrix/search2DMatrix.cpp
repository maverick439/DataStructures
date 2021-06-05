/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * 
 * */

// O(Log N) Solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0){ return false; }
        int m = matrix.size(); int n = matrix[0].size();
        //Finding the row
        int target_row = 0; 
        int row_start = 0; int row_end = m-1;
        while(row_start <= row_end){
            int mid = (row_start + row_end)/2;
            if(target >= matrix[mid][0]){ 
                target_row = max(target_row, mid); 
                row_start = mid + 1;
            }
            else{
                row_end = mid - 1;
            }
        }
        //Finding the column
        int col_start = 0; int col_end = n-1;
        while(col_start <= col_end){
            int mid = (col_start + col_end)/2;
            if(target == matrix[target_row][mid]){ return true; }
            else if(target > matrix[target_row][mid]){ col_start = mid+1; }
            else{ col_end = mid-1; }
        }
        return false;
    }
};


// O(N) solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0){ return false; }
        int m = matrix.size(); int n = matrix[0].size();
        //Finding the row
        int target_row = 0;
        for(int i=0; i<m; i++){ 
            if(target >= matrix[i][0]){ 
                target_row = i;
            }
        }
        //Finding the column
        for(int j=0; j<n; j++){
            if(matrix[target_row][j] == target){ return true; }
        }
        return false;
    }
};
