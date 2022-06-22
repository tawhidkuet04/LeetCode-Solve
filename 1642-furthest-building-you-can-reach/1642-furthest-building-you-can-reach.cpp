class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int> , greater<int> > pq;
        
        long long sum = 0 ;

        int sz = heights.size();
        
        for(int index = 1; index < sz; index ++ ){
            int diff = heights[index] - heights[index - 1];
            if( diff > 0 ){
                if(pq.size() < ladders){
                     pq.push(diff);
                }else{
                    if(!pq.empty() && pq.top() < diff){
                        sum += pq.top();
                        cout << sum << endl;
                        pq.pop();
                        pq.push(diff);
                    }else{
                        sum += diff;
                    }
                    
                    if(sum > bricks){
                            return index - 1;
                      }
                }
            }
            
        }
        
        if(sum <= bricks){
             return heights.size() - 1;
          }
        
        return -1;
    }
};


// 14  15
// 5 + 2 

// 1 1 10 10  ,,,, 2 2
    
// 4,12,2,7,3,18,20,3,19
    
// 8 0 5 0 15 2 0 17
// 8 8 13 13 28 30 30 47