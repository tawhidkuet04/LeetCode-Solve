class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans = INT_MAX, sz = nums.size();
        long long rangeSum = 0;
        
        vector<long long> cum(sz + 1, 0);
        
        deque< pair<long long,int> > dq;
        
        for(int index = 1; index <= sz; index ++ ){
            cum[index] = cum[index - 1] + nums[index - 1];
        }
        
        for(int windowEnd = 1; windowEnd <= sz; windowEnd ++){
            rangeSum = cum[windowEnd];
            
            if( rangeSum >= k){
                ans = min( ans, windowEnd);
            }
            
            while( !dq.empty() &&  (rangeSum - dq.front().first) >= (long long )k ){
                int range = windowEnd - dq.front().second;
                ans = min( ans, range);
                dq.pop_front();
            }
            
            while( !dq.empty()  && dq.back().first > rangeSum){
                dq.pop_back();
            }   
            dq.push_back(make_pair(rangeSum, windowEnd));
        }
        
        return (ans == INT_MAX) ? -1 : ans;
        
    }
};

// 2 1 3
    
    
//     2 
    
    



// 2 1 3
    
// 5 2 -4
    
    
//     3