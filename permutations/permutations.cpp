class Solution {
public:
    
    void generatePermutation(int index, vector<int> &nums, vector<int> &permutation,
                             vector< vector<int> > &ans,  unordered_map<int,int> &takenMp){
        
        if(index >= nums.size()){
            ans.push_back(permutation);
            return;
        }
        for(int start = 0; start < nums.size(); start ++ ){
              if(takenMp[start] == 0){
                  takenMp[start] = 1;
                  permutation.push_back(nums[start]);
                  generatePermutation(index + 1, nums, permutation, ans, takenMp);
                  takenMp[start] = 0;
                  permutation.pop_back();
              }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > ans;
        vector <int> permutation;
        unordered_map<int,int> takenMp;
        
        generatePermutation(0, nums, permutation, ans, takenMp);
        
        return ans;
        
        
    }
};

















