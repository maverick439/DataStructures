/**
 * Write an efficient algorithm that searches for a target value in an m x n integer matrix. 
 * 
 * The matrix has the following properties:
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
 * Output: true
 * 
 * 1  4  7  11 15
 * 2  5  8  12 19
 * 3  6  9  16 22
 * 10 13 14 17 24
 * 18 21 23 26 30
 * 
 * https://leetcode.com/explore/interview/card/microsoft/47/sorting-and-searching/195/
 * */


/**
 * Concept:
 * Search from the top-right element and reduce the search space by one row or column at each time.
**/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); int n = matrix[0].size();
        int r = 0; int c = n-1;
        while(r < m && c >= 0){
            if(matrix[r][c] == target){ return true; }
            matrix[r][c] > target ? c-- : r++;
        }
        return false;
    }
};
