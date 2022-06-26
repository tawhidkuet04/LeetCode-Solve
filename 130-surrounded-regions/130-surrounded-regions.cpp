class Solution {
    int rowSize, colSize;
    int fx[4] = {0,0,+1,-1};
    int fy[4] = {+1,-1,0,0};
public:
    
    bool isValid(int row,int col,vector<vector<char>>& board, vector< vector<int> > &vis){
        if(row >= 0 && row < rowSize && col >= 0 && col < colSize && !vis[row][col] &&
          board[row][col] == 'O'){
            return true;
        }
        return false;
    }
    
    void dfs(int row, int col, 
             vector<vector<char>>& board,
             vector< vector<int> > &vis, bool replace){
        
        vis[row][col] = 1;
        
         if(replace){
             cout << row << " " << col << endl;
              board[row][col] = 'X';
          }
        
        for(int index = 0; index < 4; index ++ ){
            int newRow = fx[index] + row;
            int newCol = fy[index] + col;
            
            if(isValid(newRow, newCol, board, vis)){
               
                dfs(newRow, newCol, board, vis, replace);
                
            }
        }
        
    }
    
    
    void solve(vector<vector<char>>& board) {
        rowSize = board.size();
        colSize = board[0].size();
        
        
        vector< vector<int> > vis(rowSize, vector<int> (colSize, 0));
        
        for(int index = 0; index < colSize; index ++ ){
            if(!vis[0][index] && board[0][index] == 'O'){
                dfs(0, index, board, vis, false);
            }
        }
        
         for(int index = 0; index < rowSize; index ++ ){
            if(!vis[index][0] && board[index][0] == 'O'){
                dfs( index, 0,  board, vis, false);
            }
        }
        
        
        for(int index = 0; index < colSize; index ++ ){
            if(!vis[rowSize - 1][index] && board[rowSize - 1][index] == 'O'){
                dfs(rowSize - 1, index, board, vis, false);
            }
        }
        
        for(int index = 0; index < rowSize; index ++ ){
            if(!vis[index][colSize - 1] && board[index][colSize - 1] == 'O'){
                dfs( index, colSize - 1,  board, vis, false);
            }
        }
        
        for(int row = 1; row < rowSize; row ++ ){
            for(int col = 1; col < colSize; col ++ ){
                if(!vis[row][col] && board[row][col] == 'O'){
                    dfs(row, col, board, vis, true);
                }
            }
        }
    }
};