/*
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
https://leetcode.com/problems/spiral-matrix/
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row_begin = 0;
        int row_end = matrix.size()-1;
        int col_begin = 0;
        int col_end = matrix[0].size()-1;
        
        while(row_begin <= row_end && col_begin <= col_end){
            // Traverse Right
            for(int i=col_begin;i<=col_end;i++){
                result.push_back(matrix[row_begin][i]);    
            }
            row_begin++;
            //Traverse Down
            for(int i=row_begin;i<=row_end;i++){
                result.push_back(matrix[i][col_end]);
            }
            col_end--;
            //Traverse Left
            if(row_begin <= row_end){
                for(int i=col_end;i>=col_begin;i--){
                    result.push_back(matrix[row_end][i]);
                }
            }
            row_end--;
            //Traverse Up
            if(col_begin <= col_end){
                for(int i=row_end;i>=row_begin;i--){
                    result.push_back(matrix[i][col_begin]);
                }
            }
            col_begin++;
        }
        return result;
        
    }
};


/*
1,2,3 
4,5,6 
7,8,9

i=0 to 2 | j=0
i=2 | j=0 to 2
i=2 to 0 | j=2
i=0 | j=2 to 1

 1  2  3  4  5
 6  7  8  9 10
11 12 13 14 15

rows = 3
cols = 5

R - 5
D - 2
L - 4
U - 1


*/

// More Optimized Solution
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0){ return result; }
        int row_begin = 0;
        int row_end = matrix.size()-1;
        int col_begin = 0;
        int col_end = matrix[0].size()-1;
        int m = row_end+1; 
        int n = col_end+1;
        
        while(result.size() < m*n){
            for(int i=col_begin; i<=col_end && result.size()<m*n;i++)
                result.push_back(matrix[row_begin][i]);
            
            for(int i=row_begin+1; i<=row_end-1 && result.size()<m*n;i++)
                result.push_back(matrix[i][col_end]);
            
            for(int i=col_end; i>=col_begin && result.size()<m*n;i--)
                result.push_back(matrix[row_end][i]);
            
            for(int i=row_end-1; i>=row_begin+1 && result.size()<m*n;i--)
                result.push_back(matrix[i][col_begin]);
            
            row_begin++; col_begin++; row_end--; col_end--;
        }
        return result;
    }
};