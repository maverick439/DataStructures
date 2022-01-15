/**
 * 
 * You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
 * You may assume all four edges of the grid are surrounded by water.
 * The area of an island is the number of cells with a value 1 in the island.
 * Return the maximum area of an island in grid. If there is no island, return 0.
 * 
 * https://leetcode.com/problems/max-area-of-island/
 * 
 * */

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0; int island = 0;
        if(grid.size() == 0){ return maxArea; }
        int row_begin = 0;  int row_end = grid.size();
        int col_begin = 0;  int col_end = grid[0].size();
        //DFS Based Approach
        for(int i=row_begin; i < row_end; i++){
            for(int j=col_begin; j < col_end; j++){
                if(grid[i][j] == 1){
                    int localArea = 1;
                    dfs(grid,i,j,localArea);
                    maxArea = max(localArea, maxArea);
                    island++;
                }
            }
        }
        return maxArea;
    }
private:
    void dfs(vector<vector<int>>&grid, int row, int col, int &localArea){
        grid[row][col] = 2;
        for(auto d : dir){
            int next_row = row + d.first;
            int next_col = col + d.second;
            
            if(next_row>=0 && next_row<grid.size() && next_col>=0 && next_col< grid[0].size() && grid[next_row][next_col] == 1){
                localArea++;
                dfs(grid, next_row, next_col, localArea);
            }
        }
    }
private:
    vector<pair<int,int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};
};

// APPROACH 2 : DFS ===============================

class Solution {
public:
    int maxAll = 0; int maxNow = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;  
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                int island_count = 0;
                if(grid[i][j] == 1){
                    maxNow = 0;
                    dfs(grid, i, j);
                }
            }
        }
        return maxAll;
    }
    
    void dfs(vector<vector<int>>&grid, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())   return;
        if(grid[r][c] != 1) return;
        maxNow++;
        grid[r][c] = -1;
        
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
        
        maxAll = max(maxAll, maxNow);
    }
};