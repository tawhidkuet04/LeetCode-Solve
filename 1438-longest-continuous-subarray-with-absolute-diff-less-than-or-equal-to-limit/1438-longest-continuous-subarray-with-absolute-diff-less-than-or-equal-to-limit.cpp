class Solution {
public:
    
    
    void  removeElement(int start, deque<int> &smaller,
                      deque<int> &larger){
        
        while(!smaller.empty() &&   smaller.back()  < start){
            smaller.pop_back();
        }
        
        while(!larger.empty() && larger.back() < start){
            larger.pop_back();
        }
        
    }
    
    void insertElement(int num, int start, int end, deque<int> &smaller,
                      deque<int> &larger, vector<int>& nums){
        removeElement(start, smaller, larger);
        
        while(!smaller.empty() && nums[smaller.front()] > nums[end]){
            smaller.pop_front();
        }
        
        smaller.push_front(end);
        
        while(!larger.empty() && nums[larger.front()] < nums[end]){
            larger.pop_front();
        }
        
        larger.push_front(end);
      
    }
    
    bool isValid(deque<int> &smaller, deque<int> &larger, int limit, vector<int> &nums){
        if(  (nums[larger.back()] - nums[smaller.back()]) <= limit) return true;
        else return false;
    }
    
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> smaller, larger;
        
        int windowStart = 0, ans = 0;
        int sz = nums.size();
        
        for(int windowEnd = 0 ; windowEnd < sz; windowEnd ++){
            insertElement(nums[windowEnd], windowStart, windowEnd, smaller, larger, nums);
            
            while(!isValid(smaller, larger, limit, nums)){
                windowStart ++ ;
                removeElement(windowStart, smaller, larger);
            }
            
            ans = max(ans, windowEnd - windowStart + 1);
            
        }
        
        return ans;
    }
};
 
 // 7 4