
int fx[] = {0, 0, +1, -1};
int fy[] = {+1, -1, 0, 0};

class Solution {
public:
    
    
    
    bool wordSearch(int row, int col, int charIndex, string word, vector<vector<char>>& board){
        if (charIndex >= word.size()){
            return true;
        }
        
         if ( row <  0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[charIndex]){
                        return false;
                    }
        bool isFound = false;
         board[row][col] = '*';
        for(int index = 0; index < 4; index ++){
            int newRow = fx[index] + row;
            int newCol = fy[index] + col;
           

               
                isFound |= wordSearch(newRow, newCol, charIndex + 1, word, board);
                if(isFound){
                    return true;
                }
                // board[newRow][newCol] = word[charIndex];
            }
     board[row][col] = word[charIndex];
    
        return isFound;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int row = 0; row < board.size(); row ++){
            for(int col = 0; col < board[0].size(); col ++){
                if(board[row][col] == word[0]){
                   
                   bool isFound =  wordSearch(row, col, 0, word, board);
                   
                    if(isFound){
                        return true;
                    }
                }
            }
        }
        
        return false;
        
        
    }
};