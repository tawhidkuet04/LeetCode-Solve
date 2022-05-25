class Solution {
public:
    void getStartPoint(vector<vector<char>> &grid, pair<int,int> &startPoint){
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        for(int row = 0; row < rowSize; row ++ ){
            for(int col = 0; col < colSize; col ++ ){
                if(grid[row][col] == '*'){
                    startPoint = make_pair(row , col);
                    return ;
                }
            }
        }
    }
    
    
    bool isValid(vector<vector<char>> &grid, int row, int col){
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        if(row >= 0 && row < rowSize && col >= 0 && col < colSize && grid[row][col] != '.' && grid[row][col] != 'X'){
            return true;
        }
        
        return false;
        
    }
    int bfs(vector<vector<char>> &grid){
        pair<int,int> startPoint;
        
        getStartPoint(grid, startPoint);
        
        queue< pair<int ,int> > q;
        
        q.push(startPoint);
        
        int x = startPoint.first;
        int y = startPoint.second;
        
        grid[x][y] = '.';
        
        int minStep = 0 ;
        
        int fx[4] = {0,0,+1,-1};
        int fy[4] = {+1,-1,0,0};
        
        while(!q.empty()){
            int qSize = q.size();
            
            for(int index = 0; index < qSize; index ++ ){
                pair<int,int> curCell = q.front();
                q.pop();
                
                int curRow = curCell.first;
                int curCol = curCell.second;
                
                for(int dir = 0; dir < 4; dir ++ ){
                    int newRow = curRow + fx[dir];
                    int newCol = curCol + fy[dir];
                    
                    if(isValid(grid, newRow, newCol)){
                        if(grid[newRow][newCol] == '#'){
                            return minStep + 1;
                        }else{
                            q.push(make_pair(newRow, newCol));
                            grid[newRow][newCol] = '.';
                        }
                    }
                }
                
            }
            
            minStep ++;
            
            
        }
        
        return -1;
    }
    
    int getFood(vector<vector<char>>& grid) {
        return bfs(grid);
    }
};