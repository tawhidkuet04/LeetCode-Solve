class Solution {
public:
    
    
    int getLisIndex( vector<int> &lis, int num){
        int lo = 0, hi = lis.size() - 1;
        while(lo <= hi){
            int mid = (lo + (hi-lo)/2);
            
            if(lis[mid] == num){
                return mid;
            }else if (lis[mid] < num){
                 lo = mid + 1;
            }else{
                 hi = mid - 1;
            }
        }
        return lo;
    }
    
    
    // 1 2 4 6 9
    
    int lengthOfLIS(vector<int>& nums) {
         vector<int> lis;
         int sz = nums.size();
         int lisIndex = 0;
         for(int index = 0; index < sz; index ++ ){
             if(lisIndex == 0){
                 lis.push_back(nums[index]);
                 lisIndex ++ ;
             }else{
                 if(lis[lisIndex - 1] < nums[index]){
                     lis.push_back(nums[index]);
                     lisIndex ++;
                 }else{
                     int insertIndex = getLisIndex(lis, nums[index]);
                     cout << insertIndex << endl;
                     lis[insertIndex] = nums[index];
                 }
                 
             }
         }
        
        return lis.size();

    }
};