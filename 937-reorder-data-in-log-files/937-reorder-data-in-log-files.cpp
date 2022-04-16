class Solution {
public:
  
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;
        int count = 0;
        
        for(int i = 0; i < logs.size(); i ++ ){
            if (logs[i].back() >= 'a' && logs[i].back() <= 'z'){
                ans.insert(ans.begin(), logs[i]);
                count += 1;
            }else{
                ans.push_back(logs[i]);
            }
         }
        
        sort(ans.begin(), ans.begin() + count, [](const auto s1, const auto s2){
            string aa = s1.substr(s1.find(' '));
            string bb = s2.substr(s2.find(' '));
        
            return (aa == bb) ? s1 < s2 : aa < bb;
        });
        return ans;
    }
};