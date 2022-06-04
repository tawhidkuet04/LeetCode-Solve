class Solution {
public:
    
    int getMaxProduct(int start, int end,  vector<int> & cumOne, vector<int>& nums){
         int totalNeg = cumOne[end + 1] - cumOne[start];
          if(totalNeg % 2 == 0){
              return (end - start + 1);
          }
        
        int mx = 0;
         // 0 1 2 3 4 5
         //   1 1
        
    // index + 1
        for(int index = start; index <= end; index ++){
            if(nums[index] < 0){
                int leftNeg = cumOne[index] - cumOne[start];
                int rightNeg = cumOne[end + 1] - cumOne[index + 1];
                if(leftNeg % 2 == 0){
                    mx = max(mx, index - start);
                }
                if(rightNeg % 2 == 0){
                     mx = max(mx, end - index);
                }
                
            }
        }
        return mx;
    }
    
    
    int getMaxLen(vector<int>& nums) {
        int sz = nums.size();
        vector< pair<int,int> > splitIndex;
        vector<int> cumOne(sz + 1, 0);
        
        int lo = 0;
        
        for(int index = 0; index < sz; index ++ ){
            if(nums[index] == 0){
                if((index - 1) >= 0){
                    splitIndex.push_back(make_pair(lo, index - 1));
                }
                lo = index + 1;
            }
            
            if(nums[index] < 0){
                cumOne[index + 1] = cumOne[index] + 1;
            }else{
                cumOne[index + 1] = cumOne[index];
            }
        }
        
         splitIndex.push_back(make_pair(lo, sz - 1));
        
        int ans = 0;
        
        for(int index = 0; index < splitIndex.size(); index ++){
            ans = max(ans, getMaxProduct(splitIndex[index].first, splitIndex[index].second, cumOne, nums));
        }
        return ans;
    }
};

// [1,-2,-3,4]
    
// 5 1 3 4 2
    
//   1 1 -1 -1 -1 1 1 1 1  1 1 1 1 
    
//    2 3 8 2
   