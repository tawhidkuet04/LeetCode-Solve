class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> arr;
        int size = s.size();
        int cnt = 0 ;
        for(int index = 1 ; index < size; index ++ ){
            if(s[index] != s[index - 1]){
                arr.push_back(cnt + 1);
                cnt = 0;
            }else{
                cnt ++ ;
            }
        }
         arr.push_back(cnt + 1);
       
        int ans = 0 ;
        
        for(int index = 1; index < arr.size(); index ++ ){
            cout << arr[index];
            ans += min(arr[index], arr[index - 1]);
        }
        return ans;
    }
};