int largestMagicSquare(vector<vector<int>>& grid) {
    int m = grid.size(); int n = grid[0].size();

    for(int sz = min(m,n); sz > 1; sz--){
        for(int row = 0; row <= m - sz; row++){
            for(int col = 0; col <= n - sz; col++){
                int row_sum = 0, col_sum = 0, diagonal_sum = 0, anti_diagonal_sum = 0;
                bool flag = true;

                for(int i=0; i<sz; i++){ row_sum += grid[row][col+i]; }
                for(int i=0; i<sz; i++){ col_sum += grid[row+i][col]; }
                for(int i=0; i<sz; i++){ diagonal_sum += grid[row+i][col+i]; }
                for(int i=0; i<sz; i++){ anti_diagonal_sum += grid[row+i][col + (sz-1) - i]; }

                if(diag_sum != anti_diag_sum || diag_sum != row_sum || diag_sum != col_sum) continue;

                // check if all rows have same sum
				for(int i{1}, cur_row_sum{0}; i < sz && flg; i++, cur_row_sum=0) {
					for(int j = 0; j < sz; j++) 
						cur_row_sum += grid[row + i][col + j];
					flg = cur_row_sum == row_sum;
				}
				if(!flg) continue; // row with different sum was found
				
				// check if all columns have same sum
				for(int i{1}, cur_col_sum{0}; i < sz && flg; i++, cur_col_sum=0) {
					for(int j = 0; j < sz; j++) 
						cur_col_sum += grid[row + j][col + i];
					flg = cur_col_sum == col_sum;
				}
				if(!flg) continue; // col with different sum was found
				return sz;  // every sum was found to be same and thus this is largest magic sqaure in given matrix
                
            }
        }
    }   
    return 1; 
    
}