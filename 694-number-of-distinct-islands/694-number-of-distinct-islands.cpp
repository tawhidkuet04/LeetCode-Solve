class Solution {
public:
    int fx[4] = {0,0,1,-1};
    int fy[4] = {1,-1,0,0};
    char dir[4] = {'r', 'l', 'd', 'u'};
    int rowSize, colSize;
    
    
    bool isValid(int row, int col,
                vector<vector<int>>& grid,
                vector<vector<int>>& vis){
        if(row >=0 && row < rowSize && col >= 0 && col < colSize && grid[row][col] 
          && !vis[row][col]){
           return true;
        }
        
        return false;
    }
    
    void dfs( int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis, string &hash){

        vis[row][col] = 1 ;
    
        for(int index = 0; index < 4; index ++ ){
            int newRow = row + fx[index];
            int newCol = col  + fy[index];
            if(isValid(newRow, newCol, grid, vis)){
                hash += dir[index];
                dfs(newRow, newCol, grid, vis, hash);
            }
        }
        hash += 'e';
        
        
    }
    
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        rowSize = grid.size();
        colSize =  grid[0].size();
        vector<vector<int>> vis(rowSize, vector<int> (colSize, 0));
        
        unordered_set<string> st;
        
        for(int row = 0; row < rowSize; row ++ ){
            for(int col = 0; col < colSize; col ++ ){
                if(!vis[row][col] && grid[row][col]){
                    string hash = "s";
                    dfs(row, col, grid, vis, hash);
                    st.insert(hash);
                }  
            }
        }
        
        return st.size();
    }
};

