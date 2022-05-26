class Solution {
public:
    
    int setIthBit(int i, int n){
        return (n | (1 << i));
    }
    
    int getIthBit(int i, int n){
        return (1 << i ) & n;
    }
    // 0100
    // 0110
    
    int getNeighbours(vector<vector<int>>& board, int fx[], int fy[], int row, int col){
        int rowSize = board.size();
        int colSize = board[0].size();
        
        int cnt = 0;
        
        for(int index = 0; index < 8; index ++ ){
            int newRow = row + fx[index];
            int newCol = col + fy[index];
            
            if(newRow >= 0 && newRow < rowSize && newCol >= 0 && newCol < colSize && (getIthBit(0, board[newRow][newCol])) ){
                cnt ++;
            }
        }
        
        return cnt;
    }
    
    
    bool isLiveCell(int n){
        if (getIthBit(0,n)){
            return true;
        }
        return false;
    }
    
    bool isDeadCell(int n){
        if(getIthBit(0,n)){
            return false;
        }
        return true;
    }
    
    
    void gameOfLife(vector<vector<int>>& board) {
        int rowSize = board.size();
        int colSize = board[0].size();
        
        int fx[8] = {0, 0 , +1, -1, + 1, -1, - 1, +1};
        int fy[8] = {+1, - 1, 0, 0, + 1, +1, - 1, - 1};
        
        for(int row = 0; row < rowSize; row ++){
            for(int col = 0; col < colSize; col ++ ){
                int neighbours = getNeighbours(board,  fx, fy, row, col);
                
                if(isLiveCell(board[row][col])){
                    if (neighbours == 2 ||  neighbours == 3){
                        board[row][col] = setIthBit(1,board[row][col]);
                    }  
                }else{
                    if( neighbours == 3){
                         board[row][col] = setIthBit(1,board[row][col]);
                    }
                }
            }
        }
        
        for(int row = 0; row < rowSize; row ++){
            for(int col = 0; col < colSize; col ++ ){
                if(getIthBit(1, board[row][col])){
                      board[row][col] = 1;
                }else{
                      board[row][col] = 0;
                }
            }
        }
        
    }
};