
int fx[] = {0, 0, +1, -1};
int fy[] = {+1, -1, 0, 0};

class Solution {
public:
    
    
    
    bool wordSearch(int row, int col, int charIndex, string word, vector<vector<char>>& board){
        if (charIndex >= word.size()){
            return true;
        }
        
        bool isFound = false;
        
        for(int index = 0; index < 4; index ++){
            int newRow = fx[index] + row;
            int newCol = fy[index] + col;
           
            if ( (newRow >= 0 && newRow < board.size()) && (newCol >= 0 && newCol < board[0].size()) && board[newRow][newCol] == word[charIndex]){
                board[newRow][newCol] = '*';
                isFound |= wordSearch(newRow, newCol, charIndex + 1, word, board);
                // if(isFound){
                //     return true;
                // }
                 board[newRow][newCol] = word[charIndex];
            }
        }
        
        return isFound;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int row = 0; row < board.size(); row ++){
            for(int col = 0; col < board[0].size(); col ++){
                if(board[row][col] == word[0]){
                   board[row][col] = '*';
                   bool isFound =  wordSearch(row, col, 1, word, board);
                   board[row][col] = word[0];
                    if(isFound){
                        return true;
                    }
                }
            }
        }
        
        return false;
        
        
    }
};