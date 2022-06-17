struct Node{
    int x;
    int y;
    int dis;
    
    Node(int x, int y, int dis){
        this->x = x;
        this->y = y;
        this->dis = dis;
    }
};

class Solution {
public:
     vector<pair<int,int>> dir={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},
                                           {2,-1},{2,1},{1,2}};
    
    
    
    int bfs(int x, int y){
        queue< Node > q;
        
        q.push(Node(0,0,0));
        
        int mp[606][606]={0};
        
        mp[302][302] = 1;
        
        int step = 0;
        
        while(!q.empty()){
            
            
           
            int qSize = q.size();
            for(int qIndex = 0; qIndex < qSize; qIndex ++ ){
                
                auto front = q.front();
                
               if(front.x == x && front.y == y) return step;
            
                q.pop();
               for(int index = 0; index < 8; index ++ ){
                int newRow = front.x + dir[index].first;
                int newCol = front.y + dir[index].second;
                
                if(  mp[newRow + 302][newCol+ 302] == 0){
                     mp[newRow+ 302][newCol+ 302] = 1;
                    q.push(Node(newRow, newCol, front.dis + 1));
                }
            }
            }
            
            step ++;

        }
        
        return 0;
        
        
    }
    int minKnightMoves(int x, int y) {
        return bfs(x,y);
    }
};