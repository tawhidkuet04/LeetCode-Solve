class Solution {
public:
    
    
    void makeCombinationSum(int index, vector<int> &candidates, 
                            vector< vector<int> > &ans, 
                            vector<int> &combination, int sum, int target,
                            unordered_map<string,int> &mp, string combStr){
        if( sum > target || index >= candidates.size()) {
            return;
        }
        
        if( sum == target){
            if(mp[combStr] == 0){
                mp[combStr] = 1;
                ans.push_back(combination);
            }
            
            return;
        }
        
            combStr += (index + '0');
            sum += candidates[index];
            combination.push_back(candidates[index]);
            makeCombinationSum( index, candidates, ans, combination, sum, target, mp, combStr);
           if(combination.size() > 0){
            sum -= candidates[index];
            combStr.pop_back();
            combination.pop_back();
            makeCombinationSum( index + 1, candidates, ans, combination, sum, target,mp, combStr);
        
        }
          
        
    }
    

    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector< vector<int> > ans;
        vector<int>combination;
        unordered_map<string,int>mp;
        sort(candidates.begin(), candidates.end());
        makeCombinationSum( 0, candidates, ans, combination , 0, target, mp, "");
        
        return ans;
    }
};