
int fx[] = {0, 0, +1, -1};
int fy[] = {+1, -1, 0, 0};

class Solution {
public:
    
    
    
    bool wordSearch(int row, int col, int charIndex, string word, vector<vector<char>>& board, int visited[7][7]){
        if (charIndex >= word.size()){
            return true;
        }
        
        bool isFound = false;
        
        for(int index = 0; index < 4; index ++){
            int newRow = fx[index] + row;
            int newCol = fy[index] + col;
           
            if ( (newRow >= 0 && newRow < board.size()) && (newCol >= 0 && newCol < board[0].size()) && board[newRow][newCol] == word[charIndex] && !visited[newRow][newCol]){
                visited[newRow][newCol] = 1;
                isFound |= wordSearch(newRow, newCol, charIndex + 1, word, board , visited);
                if(isFound){
                    return true;
                }
                visited[newRow][newCol] = 0;
            }
        }
        
        return isFound;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int visited[7][7] = {0};
        for(int row = 0; row < board.size(); row ++){
            for(int col = 0; col < board[0].size(); col ++){
                if(board[row][col] == word[0]){
                    memset(visited, 0, sizeof(visited));
                    visited[row][col] = 1;
                   bool isFound =  wordSearch(row, col, 1, word, board, visited);
                    if(isFound){
                        return true;
                    }
                }
            }
        }
        
        return false;
        
        
    }
};