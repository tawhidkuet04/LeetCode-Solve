class Solution {
public:
    void insertElement(int index, deque<int> &dq, vector<int>& nums, int k ){
        while(!dq.empty() && dq.back() == (index - k )){
            dq.pop_back();
        }
        
        while( !dq.empty() && (nums[index] > nums[dq.front()] )){
            dq.pop_front();
        }
        dq.push_front(index);
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        
        for(int index = 0; index < k - 1; index ++ ){
            insertElement(index, dq, nums, k);
        }
        
        int size = nums.size();
        
        for(int index = k - 1; index < size; index ++ ){
            
            insertElement(index, dq, nums, k);
            
            ans.push_back(nums[dq.back()]);
        }
        
        return ans;
    }
};


// 3 

// 2 7 

 // 6 7