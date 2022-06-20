class Solution {
public:
    
    bool isSubstring(string &a, string &b){
        int i = a.size() - 1, j = b.size() - 1;
        
        while( j >= 0 && i >= 0){
            if(a[i] == b[j]){
                i --; 
                j -- ;
            }else{
                return false;
            }
        }
        
        if( i < 0) return true;
        else return false;
        
        
    }
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string, int > mp;
        vector< pair<int, string> > arr;
        for(auto &word: words){
            mp[word] ++ ;
            arr.push_back({word.size(), word});
        }
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size(); i ++ ){
            for(int j = i + 1; j < arr.size(); j ++ ){
                if(isSubstring(arr[i].second, arr[j].second)){
                    mp[arr[i].second] -- ;
                    break;
                }
            }
        }
        
        int ans = 0, count = 0;
        for( auto keyVal: mp){
            if(keyVal.second > 0){
                ans += keyVal.first.size();
                count ++ ;
            }
        }
        
        
        return ans + count;
       
        
        
    }
};

