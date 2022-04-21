class Solution {
public:
    bool isPalindrome(string s){
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
    
    void palindromePartition(int index, string &s, vector< vector<string> > &ans, vector<string> &partionedStrings){
        if(index >= s.size()){
            ans.push_back(partionedStrings);
            return;
        }
        
        for(int start = index; start < s.size(); start ++ ){
            string subStr = s.substr(index, start - index + 1);
            if(isPalindrome(subStr)){
                partionedStrings.push_back(subStr);
                palindromePartition(start + 1, s, ans, partionedStrings);
                partionedStrings.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector< vector<string> > ans;
        vector<string>partionedStrings;
        
        palindromePartition(0, s, ans, partionedStrings);
        
        return ans;
        
        
    }
};