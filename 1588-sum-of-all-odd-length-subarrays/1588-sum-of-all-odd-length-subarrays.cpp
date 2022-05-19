class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        int sum = 0, sz = arr.size() ;
        
        for(int index = 0; index < sz; index ++ ){
            int leftPortion = index + 1;
            int rightPortion = sz - index ;
            
            int totalPortion = leftPortion * rightPortion ;
            
            int oddLengthPortion =  totalPortion / 2;
            if(totalPortion % 2){
                oddLengthPortion += 1;
            }
            sum += oddLengthPortion * arr[index];
        }
        
        return sum;

    }
};
  

//     0 1 2 3 4 
// // [1,4,2,5,3]
//           3 
//           3
//           5

//  1 - 3
//  3 - 2
//  5 - 1
     
        
     
     
