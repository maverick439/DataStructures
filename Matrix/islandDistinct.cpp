/**
 * You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
 * You may assume all four edges of the grid are surrounded by water.An island is considered to be the same as another 
 * if and only if one island can be translated (and not rotated or reflected) to equal the other.
 * Return the number of distinct islands.
 * 
 * Input: grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
 * Output: 3
 * 
 * Strings : 
 * srrrrrerrrrrrere 
 * srrrrrrrere 
 * srrrrrrrrreerrre 
 * srrrrrrrere
 * 
 * 1 1 0 1 1
 * 1 0 0 0 0
 * 0 0 0 0 1
 * 1 1 0 1 1
 * 
 * https://leetcode.com/problems/number-of-distinct-islands/
 * 
 * */

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.size() == 0){ return 0; }
        int row_begin = 0; int row_end = grid.size();
        int col_begin = 0; int col_end = grid[0].size();
        
        unordered_set<string> islands;
        
        for(int i=row_begin; i<row_end; i++){
            for(int j=col_begin; j<col_end; j++){
                if(grid[i][j] == 1){
                    string s = "s"; // start of island
                    dfs(grid, i, j, s);
                    cout<<s<<endl;
                    islands.insert(s);
                }
            }
        }
        return islands.size();
    }
private:
    void dfs(vector<vector<int>>&grid, int row, int col, string&s){
        if(row<0 || row >= grid.size() || col<0 || col >= grid[0].size() || grid[row][col] == 0){
            return;   
        }
        
        grid[row][col] = 0; 
        int k = 0;
        for(auto &d : dir){
            s += path[k]; // marking the island as string
            dfs(grid, row+d.first, col+d.second, s);
        }
        s = s+"e"; // end of island
    }
private:
    vector<pair<int, int>>dir {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<string> path{"r", "l", "d", "u"};
};