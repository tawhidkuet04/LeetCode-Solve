class Solution {
public:
    int lowerBound(int lo, int hi, vector<int> & arr, int target){
        int ans = lo;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(arr[mid] <= target){
                ans = mid ;
                lo = mid + 1;
            }else hi = mid - 1;
        }
        return ans;
    }

    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int size = nums.size();
 
        set<int> st;
        
        for( auto &num: nums){
            st.insert(num);
        }
        
        vector<int> arr;
        
        for(auto num : st){
            arr.push_back(num);
        }
        
        int maxCount = 0 ;
        int arrSize = arr.size();
        
        for(int index = 0; index <arrSize ; index ++ ){
            int target = arr[index] + size - 1;
            
            int targetIndex = lowerBound(index, arrSize - 1, arr, target);
            
            maxCount = max(maxCount, targetIndex - index + 1);
        }
       
        return (size - maxCount);
    }
    
};

// 1 2 3 4  -> 7 

// 10 11 12 13 -> 46
    
// 100 101 102 103 -> 406

// 1000 1001 1002 10003 -> 4006
    
    
// sum = 1111

// 1 2 3 4 5   -> 15

// 2 3 4 5 6    -> 20

// 3 4 5 6 7    -> 25

// 5 6 7 8 9  -> 35

// 6 7 8 9 10 -> 40
    
    
//     17