class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> arr;
        int size = s.size();
        int cnt = 1 , ans  = 0 , prevCount = 0 ;
        for(int index = 1 ; index < size; index ++ ){
            if(s[index] != s[index - 1]){
               ans += min(prevCount, cnt);
                prevCount = cnt;
                cnt = 1;
            }else{
                cnt ++ ;
            }
        }
        ans += min(prevCount, cnt);
        
        return ans;
    }
};