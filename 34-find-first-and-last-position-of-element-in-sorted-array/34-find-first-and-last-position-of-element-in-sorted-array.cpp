class Solution {
public:
    int binarySearch(int lo , int hi , int num , vector<int>& nums , bool flag){
        int mid , ans = -1;
        while( lo <= hi ){
            mid = lo + ( hi - lo )/2;
            if ( nums[mid] > num ){
                hi = mid -1 ;
            }else if ( nums[mid] < num){
                lo = mid + 1 ;
            }else {
                ans = mid ;
                if ( flag == false){
                     hi = mid - 1 ;
                }else {
                     lo = mid + 1;
                }
               
            }
        }
        return ans;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower_bound = binarySearch(0,nums.size()-1,target,nums,false);
        int upper_bound = binarySearch(0,nums.size()-1,target,nums,true);
        vector < int > ans;
        ans.push_back(lower_bound);
        ans.push_back(upper_bound);
        return ans;
        
    }
};