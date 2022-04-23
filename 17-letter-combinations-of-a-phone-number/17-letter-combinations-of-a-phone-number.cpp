class Solution {
public:
   
    
    void generateLetters(int index, vector<string> &ans, string combination, string digits,
                        string mapping[]){
        
        if(index >= digits.size()){
            ans.push_back(combination);
            return;
        }
        
        
        int number = (digits[index] - '0');
        string value = mapping[number];
        for(int start = 0 ; start < value.size(); start ++ ){
            combination += value[start];
            generateLetters(index + 1, ans, combination, digits, mapping);
            combination.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0){
            return ans;
        }
        
         string mapping[10] = {"", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        generateLetters(0, ans, "", digits, mapping);
        
       
        return ans;
    }
};