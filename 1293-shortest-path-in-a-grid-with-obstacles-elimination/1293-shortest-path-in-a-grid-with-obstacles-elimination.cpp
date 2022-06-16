struct Node{
    int row;
    int col;
    int obstacle;
    int dis;
    
    Node(int row, int col, int obstacle, int dis){
        this->row = row;
        this->col = col; 
        this->obstacle = obstacle;
        this->dis = dis;
    }
    
};


class Solution {
public:
    bool isValid(int row, int col, int rowSize, int colSize){
        if( row >= 0 && row <  rowSize && col >= 0 && col < colSize) return true;
        return false;
    }
    
    int solve(vector<vector<int>>& grid, int k){
         queue< Node > q;
         q.push(Node(0,0,k, 0));
         
         int rowSize = grid.size();
         int colSize = grid[0].size();
        
         // vector< vector<int> >  vis(rowSize, vector<int> (colSize, 0));
        
        unordered_set<string> seen;
        

        int fx[4] = {0,0,+1,-1};
        int fy[4] = {+1,-1,0,0};
        
        string hash =  to_string(0) + "." + to_string(0) + "." + to_string(k);
        seen.insert(hash);
        
         while(!q.empty()){
             
             Node top = q.front();
             q.pop();
             if(top.row == rowSize - 1 && top.col == colSize - 1){
                 return top.dis;
             }
             
             for(int index = 0; index < 4; index ++ ){
                 int newRow = fx[index] + top.row;
                 int newCol = fy[index] + top.col;
                 
                 if(isValid(newRow, newCol, rowSize, colSize)){
                     
                     int newElemination = top.obstacle - grid[newRow][newCol];
                     
                     Node newStep = Node(newRow, newCol, newElemination, top.dis + 1);
                     
                     
                       string hash =  to_string(newRow) + "." + to_string(newCol) + "." + to_string(newElemination);
      
                     
                     if(newElemination >= 0 && (seen.find(hash) == seen.end())){
                         seen.insert(hash);
                         q.push(newStep);
                       
                     }
                
                 }
                 
             }
             
         }
        
        
       return -1;
         
        
        
    }
    
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        return solve(grid, k );
    }
};