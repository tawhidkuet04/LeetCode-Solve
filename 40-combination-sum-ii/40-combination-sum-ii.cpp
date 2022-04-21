class Solution {
public:
    
    
    void findCombinations(int index, vector<int> & candidates, 
                           vector< vector<int> >& ansSet, vector<int> & combination,
                          int sum){
       if(sum == 0){
            ansSet.push_back(combination);
            return ;
        }
        
        if(sum < 0 || index >= candidates.size()){
            
            return;
        }
        
        for(int start = index; start < candidates.size(); start ++ ){
            if( candidates[start] > sum ) break;
            if(start  != index){
                if( start > 0 && candidates[start - 1] != candidates[start]){
                    combination.push_back(candidates[start]);
                   findCombinations(start + 1, candidates, ansSet, combination, sum - candidates[start]); 
                   combination.pop_back();
                }
                
            }else{
              combination.push_back(candidates[start]);
               findCombinations(start + 1, candidates, ansSet, combination, sum -candidates[start]); 
               combination.pop_back();
            }
        }
      
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector< vector<int> > ansSet;
        vector< int > combination;

        sort(candidates.begin(), candidates.end());
        findCombinations(0, candidates, ansSet, combination, target);
        

        return ansSet;
        
    }
};