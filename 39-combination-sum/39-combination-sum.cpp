class Solution {
public:
    
    
    void makeCombinationSum(int index, vector<int> &candidates, 
                            vector< vector<int> > &ans, 
                            vector<int> &combination, int sum, int target){
        if( sum == target){
            ans.push_back(combination);
            return;
        }
        if( sum > target) {
            return;
        }

        for(int start = index; start < candidates.size(); start ++){
            sum += candidates[start];
            combination.push_back(candidates[start]);
            makeCombinationSum( start, candidates, ans, combination, sum , target);
            sum -= candidates[start];
            combination.pop_back();
        }

    }
    

    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector< vector<int> > ans;
        vector<int>combination;
        makeCombinationSum( 0, candidates, ans, combination , 0, target);
        
        return ans;
    }
};