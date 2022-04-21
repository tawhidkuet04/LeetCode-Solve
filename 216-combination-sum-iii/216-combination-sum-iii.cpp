class Solution {
public:
    void findCombination(int index, int sum, int k, vector<int> &combination,
                         vector< vector<int> > &ans, int nextNum){
        
        if( index >= k){
            if( sum == 0){
                ans.push_back(combination);
            }
            return ;
        }
        if(sum < 0 ) return ;
        
        for(int start = nextNum; start <= 9; start ++ ){
            if(start > sum ) break;
            combination.push_back(start);
            findCombination(index + 1, sum - start, k , combination, ans, start + 1);
            combination.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector< vector<int> > ans ;
        vector< int > combination;
        
        findCombination(0, n, k , combination, ans, 1);
        return ans;
    }
};