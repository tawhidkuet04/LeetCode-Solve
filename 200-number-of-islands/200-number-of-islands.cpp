class Solution {
public:
    
    bool isValid(int row, int col, vector<vector<char>>& grid){
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        if( (row >= 0 && row < rowSize) && (col >= 0 && col < colSize) && grid[row][col] == '1'){
            return true;
        }
        
        return false;
    }
    
    void dfs( int row, int col, vector<vector<char>>& grid, int fx[], int fy[]){
        
        for(int index = 0; index < 4; index ++ ){
            
            int newRow = row + fx[index];
            int newCol = col + fy[index];
            if(isValid(newRow, newCol, grid)){
                grid[newRow][newCol] = '0';
                dfs(newRow, newCol, grid, fx, fy);
            }
            
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIsland = 0 ;
        int fx[4] = {0,0,+1,-1};
        int fy[4] = {+1,-1,0,0};
        
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        for(int row = 0; row < rowSize; row ++ ){
            for(int col = 0; col < colSize; col ++ ){
                if(grid[row][col] == '1'){
                    dfs(row, col, grid, fx, fy);
                    numberOfIsland ++ ;
                }
            }
        }
        
        return numberOfIsland;
        
        
    }
};