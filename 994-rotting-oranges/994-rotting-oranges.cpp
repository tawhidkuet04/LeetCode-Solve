class Solution {
public:
    
    bool isValid(int newRow, int  newCol, int rowSize, int colSize, vector<vector<int>>& grid){
        if( newRow >= 0 && newRow < rowSize && newCol >= 0 && newCol < colSize && grid[newRow][newCol] == 1) return true;
        return false;
    }
    
    int bfs(vector<vector<int>> & grid){
       queue<pair<int,int>> q;
        
       int rowSize = grid.size();
       int colSize = grid[0].size();
        
       int fx[4] = {0 , 0 , + 1 , - 1};
       int fy[4] = {+ 1, -1 , 0 , 0 };
        
       for(int row = 0; row < rowSize; row ++ ){
           for(int col = 0; col < colSize; col ++ ){
               if(grid[row][col] == 2){
                   q.push(make_pair(row, col));
               }
           }
       }
        
       int minStep = 0;
        
        while(!q.empty()){
            
            int sz = q.size();
            
            for(int index = 0; index < sz; index ++ ){
                  pair<int,int> cell = q.front();
                  q.pop();
                  
                  int curRow = cell.first;
                  int curCol = cell.second;
                  
                  for(int dirIndex = 0; dirIndex < 4; dirIndex ++ ){
                       int newRow =  curRow + fx[dirIndex];
                       int newCol = curCol + fy[dirIndex];
                        
                       if(isValid(newRow, newCol, rowSize, colSize, grid)){
                           q.push(make_pair(newRow, newCol));
                           grid[newRow][newCol] = 2;
                       }
                      
                  }
            }
            
              if(!q.empty()){
                    minStep ++;
              }
          
            
        }
        
        
        
       return (checkIfPossible(grid)) ? minStep : -1;
        
        
    }
    
    
    int checkIfPossible(vector<vector<int>>& grid){
        int rowSize = grid.size();
        int colSize = grid[0].size();
        for(int row = 0; row < rowSize; row ++ ){
            for(int col = 0; col < colSize; col ++ ){
                if(grid[row][col] == 1) return false;
            }
        }
        return true;
        
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};

// 2 1 1
// 1 1 0
// 0 1 1
    
// 2 1 1
// 0 1 1 
// 1 0 1