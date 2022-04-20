class Solution {
public:
    
    
    void makeCombinationSum(int index, vector<int> &candidates, 
                            vector< vector<int> > &ans, 
                            vector<int> &combination, int sum, int target){
        if( sum > target || index >= candidates.size()) {
            return;
        }
        
        if( sum == target){
            ans.push_back(combination);
            return;
        }
        
        sum += candidates[index];
        combination.push_back(candidates[index]);
        makeCombinationSum( index, candidates, ans, combination, sum, target);
        sum -= candidates[index];
        combination.pop_back();
        makeCombinationSum( index + 1, candidates, ans, combination, sum, target); 
    }
    

    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector< vector<int> > ans;
        vector<int>combination;
        makeCombinationSum( 0, candidates, ans, combination , 0, target);
        
        return ans;
    }
};