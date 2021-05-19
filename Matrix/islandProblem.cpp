/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

https://leetcode.com/problems/number-of-islands/

*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island_count = 0;
        if(grid.size() == 0){ return island_count; }
        // DFS based solution
        int row_begin = 0; int row_end = grid.size();
        int col_begin = 0; int col_end = grid[0].size();
        
        for(int i=row_begin;i < row_end;i++){
            for(int j=col_begin;j < col_end;j++){
                if(grid[i][j] == '1'){
                    island_count++;
                    dfs(grid,i,j);
                }   
            }
        }
        return island_count;
    }
private:
    // To mark every 1 in that island in one go
    void dfs(vector<vector<char>>& grid, int row, int col){
        grid[row][col] = '2';
        for(auto d : dir){
            int next_row = row + d.first;
            int next_col = col + d.second;
            
            if(next_row>=0 && next_row<grid.size() && next_col>=0 && next_col< grid[0].size() && grid[next_row][next_col] == '1'){
                dfs(grid, next_row, next_col);
            }
        }
    }
private:
    // To cover an entire island in one go
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//<row, column>
    
};

/** Concept
BFS + DFS
0 -> water
1 -> land
2 -> visited land
**/

/* Sample Test Cases

1 1 1 0 1 1
1 1 0 0 1 0
1 0 0 0 0 1
0 1 1 0 0 1

Output - 4

1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1

Output - 3


*/

// BFS based solution
class Solution {
public: 
    int numIslands(vector<vector<char>>& grid) {
        int island_count = 0;
        if(grid.size() == 0){ return island_count; }
        // BFS based solution
        for(int row=0;row < grid.size();row++){
            for(int col=0;col < grid[0].size();col++){
                if(grid[row][col] == '1') {
                    island_count++;
                    queue<pair<int, int>> bfs;
                    bfs.push({row, col});
                    while(!bfs.empty()) {
                        pair<int, int>visited_node = bfs.front();
                        bfs.pop();
                        for(auto d : dir) {
                            int next_row = visited_node.first + d.first;
                            int next_col = visited_node.second + d.second;
                            if(next_row >= 0 && next_row < grid.size() && next_col >= 0 && next_col < grid[0].size() && grid[next_row][next_col] == '1') {
                                grid[next_row][next_col] = '2';
                                bfs.push(make_pair(next_row, next_col));
                            }
                            
                        }
                    }
                }
            }
        }
        return island_count;
    }
private:
    // To cover an entire island in one go
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//<row, column>
};