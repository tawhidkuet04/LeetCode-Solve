class Solution {
public:
    int minSwaps(vector<int>& data) {
        int totalOne = 0 ;
        for(int &num : data){
            if(num == 1) totalOne ++ ;
        }
        int zeroCount = 0 , ans = INT_MAX, windowStart = 0, size = data.size(), oneCount = 0;
        
        for(int windowEnd = 0 ; windowEnd < size; windowEnd ++ ){
            if(data[windowEnd] == 0 ) zeroCount ++ ;
            else {
                oneCount ++;
            }
            
            if((windowEnd - windowStart) >= totalOne){
                if(data[windowStart] == 0 ) zeroCount --;
                else oneCount -- ;
                windowStart ++ ;
            }
            
            if((windowEnd - windowStart) == totalOne - 1){
                
                if(  zeroCount >= (totalOne - oneCount )){
                     ans = min(ans, zeroCount); 
                }
              
            }
            
            
        }
        return ans;
        
        
    }
};

// 1 0 1 0 1 0 0 2 0 1