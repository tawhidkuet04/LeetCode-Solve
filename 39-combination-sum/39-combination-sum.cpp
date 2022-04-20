class Solution {
public:
    
    
    void makeCombinationSum(int index, vector<int> &candidates, 
                            vector< vector<int> > &ans, 
                            vector<int> &combination, int sum, int target){
        // cout << sum << endl;
        if( sum == target){
            for(int i = 0 ; i < combination.size(); i ++) cout << combination[i]<< " " ;
            cout<<endl;
            ans.push_back(combination);
            return;
        }
        if( sum > target || index >= candidates.size()) {
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