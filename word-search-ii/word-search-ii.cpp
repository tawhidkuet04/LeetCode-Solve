class Solution {
public:
    
    
    bool isValid(int row, int col, vector< vector<char> > &board){
        int rowSize = board.size();
        int colSize = board[0].size();
        if(row < 0 || row >= rowSize || col < 0 || col >= colSize  ){
            return false;
        }
        return true;
    }
    
    void checkWord( string word, unordered_set<string> &st, vector<string> &ans){
        if(st.find(word) != st.end()){
                    
                    ans.push_back(word);
            st.erase(word);
                }
    }
    
    void solve(int row, int col, unordered_set<string> &st, 
               vector< vector<char> > &board, int vis[12][12],
               int fx[], int fy[], int &maxLength, vector<string> &ans, string &word){
        
        if(word.size() > maxLength) return ;
       
        vis[row][col] = 1;
        
        for(int index = 0; index < 4; index ++){
            int newRow = row + fx[index];
            int newCol = col + fy[index];
            if(isValid(newRow, newCol, board)
              && !vis[newRow][newCol]){
                // cout << word << endl;
                word += board[newRow][newCol];
                checkWord(word, st, ans);
                solve(newRow, newCol, st, board, vis, fx, fy, maxLength, ans, word);
                word.pop_back();
                vis[newRow][newCol] = 0;
                
            }
            
        }
        
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> st;
        
        int maxLength = 0 ;
        for(auto &str: words){
            st.insert(str);
            maxLength = max(maxLength, (int)str.size());
        }
        cout << maxLength << endl;
        
        vector<string> ans;
        
        int rowSize = board.size();
        int colSize = board[0].size();
        
        int fx[4] = {0,0,+ 1, -1};
        int fy[4] = {+1, - 1, 0 ,0};
        
        for(int row = 0 ; row < rowSize; row ++ ){
            for(int col = 0; col < colSize; col ++ ){
                int vis[12][12] = {0};
                string word = "";
                word += board[row][col];
                checkWord(word, st, ans);
                solve(row, col, st, board, vis, fx, fy, maxLength, ans, word );
            }
        }
        
        return ans;
    }
};
