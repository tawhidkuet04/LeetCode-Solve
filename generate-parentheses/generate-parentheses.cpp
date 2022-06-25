class Solution {
public:
    
    string br = "()";
    
    void solve(int open, int close, int n, string par, vector<string> &ans){

        if(n == open && open == close){
            ans.push_back(par);
            return ;
        }
        
       if(open < n) solve(open + 1, close,n, par + '(', ans);
        if(close < open) solve(open, close + 1, n, par + ')', ans);
       
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        solve(0,0,n, "", ans);
        return ans;
    }
};