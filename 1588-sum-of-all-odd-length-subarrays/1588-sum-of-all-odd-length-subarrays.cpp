class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sz = arr.size();
        
        vector<int> prefixSum(sz + 1, 0);
        
        for(int index = 1; index <= sz; index ++ ){
            prefixSum[index] = prefixSum[index - 1] + arr[index - 1];
        }
        
        int ans = 0, index = 1 ;
        
        while(index <= sz){
            for(int range = index; range <= sz; range ++){
                ans += prefixSum[range] - prefixSum[range - index];
            }
            index += 2;
        }
        return ans;
    }
};

// [1,4,2,5,3]

