class Solution {
public:
    
    
    int getSumOfFirstTwoSmaller( priority_queue<int> &q){
        int firstSmaller = q.top() * - 1;
        q.pop();
        int secondSmaller = q.top() * - 1;
        q.pop();
        return (firstSmaller + secondSmaller);
        
    }
    int connectSticks(vector<int>& sticks) {
        priority_queue<int> q;
        
        int sz = sticks.size();
        
        for(int index = 0; index < sz; index ++ ){
            q.push( - 1 * sticks[index]);
        }
        
        int ans = 0 ;
        
        while(q.size() > 1){
            int sumOfTwoSticks = getSumOfFirstTwoSmaller(q);
            ans += sumOfTwoSticks;
            q.push(sumOfTwoSticks * - 1);
        }
        
        return ans;
    }
};