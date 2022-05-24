class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        
        vector<int> ans(length,0);
        
        int sz = updates.size();
        
        // unordered_map<int,int> mp;
        
        for(int index = 0; index < sz; index ++ ){
            int startIndex = updates[index][0];
            int endIndex = updates[index][1];
            int val = updates[index][2];
            
            // mp[endIndex] = val;
            
            ans[startIndex] += val;
            
            if(endIndex < length - 1){
                 ans[endIndex + 1] -=  val;
            }
           
        }
        
        
        for(int index = 1; index < length; index ++){
            ans[index] += ans[index - 1];
        }
        
        // for(int index = 0; index < length; index ++ ){
        //     ans[index] += mp[index];
        // }
        
        return ans;
        
        
        
    }
};

// 0 1 2 3 4
    


// 0 - 2 -> -2
// 1 - 3 -> 2
// 2 - 4 -> 3
    

// 0   1   2     3   4 
// -2  2   +2+3  -2  -3
    
// -2  2+-2.  3   5.  3
    
    
//     0   1    2     3    4    5    6   7    8    9
//         -4    6         -6    8   -8             4
//     0.   -4.  2     2    2   4   4   -4  -4    -4