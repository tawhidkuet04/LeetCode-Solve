class Solution {
public:
    
    
    bool isFirstInterValBigger(vector<int> &first, vector<int> &second){
        
        if(first[1] > second[1]){
            return true;
        }else return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 1){
            return 0;
        }
        
        sort(intervals.begin(), intervals.end());
        
        int firstIndex = 0, secondIndex = 1, size = intervals.size();
        
        int ans = 0;
        
        while(secondIndex < size){
             auto &firstInterval = intervals[firstIndex];
             auto &secondInterval = intervals[secondIndex];
             
            if(firstInterval[1] > secondInterval[0]){
                ans ++ ;
                
                if(isFirstInterValBigger(firstInterval, secondInterval)){
                    firstIndex = secondIndex;
                    secondIndex ++;
                }else{
                    secondIndex ++;
                }
            }else{
                firstIndex = secondIndex;
                secondIndex ++;
            }
        }
        return ans;
        
    }
};

// 1 5
// 2 3 
// 4 6
    
// 1   3
// 1      5
//   2 3
//     3 4


// 1 5
// 1 3
// 1 2 

// 1 2 
// 1 15    
// 3 10