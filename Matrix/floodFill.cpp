/**
 * An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
 * You are also given three integers sr, sc, and newColor. 
 * You should perform a flood fill on the image starting from the pixel image[sr][sc].
 * To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally 
 * to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally 
 * to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.
 * https://leetcode.com/problems/flood-fill/
 * */

// DFS APPROACH 1
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor)
            dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c, int c0, int c1){
        if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != c0)
            return;
        
            image[r][c] = c1;
            dfs(image, r+1, c, c0, c1);
            dfs(image, r-1, c, c0, c1);
            dfs(image, r, c+1, c0, c1);
            dfs(image, r, c-1, c0, c1);
    }
};


// BFS APPROACH 2
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size();   int cols = image[0].size();
        int old_color = image[sr][sc];

        // Directions of movement
        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        //Visited array to mark 
        int seen[51][51] = {{0}};

        list<vector <int>>togo;
        togo.push_back({sr,sc});

        while(togo.size()){
            int r = togo.front()[0];    int c = togo.front()[1];
            togo.pop_front();   image[r][c] = newColor;

            for(auto&d : dir){
                int rr = r + d[0];  int cc = c + d[1];
                if(rr < 0 || rr >= rows || cc < 0 || cc >= cols) continue;
                if(image[rr][cc] != old_color) continue;
                if(seen[rr][cc]) continue;
                seen[rr][cc] = 1;
                togo.push_back({rr,cc});
            }
        }
        return image;
    }
};
