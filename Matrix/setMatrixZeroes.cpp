/**
 * Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.
 * Follow up:
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 * 
 * Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: [[1,0,1],[0,0,0],[1,0,1]]
 * https://leetcode.com/problems/set-matrix-zeroes/
 * */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>row_set; vector<int>col_set;
        int m = matrix.size(); int n = matrix[0].size();
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(matrix[i][j] == 0){
                    row_set.push_back(i);
                    col_set.push_back(j);   
                }
            }
        }
        for(int row : row_set)
            for(int j=0; j< n; j++)
                matrix[row][j] = 0;
        for(int col : col_set)
            for(int i=0; i< m; i++)
                matrix[i][col] = 0;
        
    }
};