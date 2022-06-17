class Solution {
public:
    int fx[4] = {0,0,1,-1};
    int fy[4] = {1,-1,0,0};
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
             vector<vector<int>>& vis,
             vector< pair<int,int> > & points,
             int &minRow,
             int &minCol){
        
        minRow = min(minRow, row);
        minCol = min(minCol, col);
        
        vis[row][col] = 1 ;
        points.push_back({row, col});
        
        for(int index = 0; index < 4; index ++ ){
            int newRow = row + fx[index];
            int newCol = col  + fy[index];
            if(isValid(newRow, newCol, grid, vis)){
                dfs(newRow, newCol, grid, vis, points, minRow, minCol);
            }
        }
        
        
    }
    
    
    string generateHash( vector< pair<int,int> > & points){
        string hash = "";
        
        for(int index = 0; index < points.size(); index ++ ){
            hash +=  to_string(points[index].first);
             hash +=  to_string(points[index].second);
            hash += '.';
        }
        
        return hash;
    }
    void normalizePoints( vector< pair<int,int> > & points, int &minRow, int &minCol){
        for(int index = 0; index < points.size(); index ++ ){
            points[index].first -= minRow;
            points[index].second -= minCol;
        }
         sort(points.begin(), points.end());
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        rowSize = grid.size();
        colSize =  grid[0].size();
        vector<vector<int>> vis(rowSize, vector<int> (colSize, 0));
        
        unordered_set<string> st;
        
        for(int row = 0; row < rowSize; row ++ ){
            for(int col = 0; col < colSize; col ++ ){
                if(!vis[row][col] && grid[row][col]){
                    vector< pair<int,int> > points;
                    int minRow = 1e9;
                    int minCol = 1e9;
                    dfs(row, col, grid, vis, points, minRow, minCol);
                    normalizePoints(points, minRow, minCol);
                    st.insert(generateHash(points));
                }  
            }
        }
        
        return st.size();
    }
};

