class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        vector<int> maxArr(sz, 0);
        
        maxArr[sz -1 ] = prices[sz - 1];
        
        for(int index = sz - 2; index >= 0; index -- ){
            maxArr[index] = max(prices[index], maxArr[index + 1]);
        }
        int ans = 0 ;
        
        for(int index = 0; index < sz - 1; index ++ ){
            if(maxArr[index + 1] > prices[index]){
                ans = max(ans, maxArr[index + 1] - prices[index]);
            }
        }
        
        return ans;
    }
};