class Solution {
public:
    
    string pad[10] = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    
    void solve(int index, string &digits, string comb, vector<string> &ans){
        if(index == digits.size()) {
            ans.push_back(comb);
            return;
        }
        
        string group = pad[digits[index] - '0'];
        
        for(int start = 0; start < group.size(); start ++ ){
            solve(index + 1, digits, comb + group[start], ans);
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
         vector<string> ans;
         if(digits.size() == 0) return ans;
         solve(0, digits, "", ans);
         
         return ans;
        
        
        
    }
};