class Solution {
public:

    
    int numPairsDivisibleBy60(vector<int>& time) {
        int mp[62] = {0};
        int ans = 0 ;
        for(int &num : time){
            num %= 60;
            int numToFind = (60 - num) % 60 ;
            ans += mp[numToFind];
            mp[num] ++ ;
            // cout << num << endl;
        }
        
       
       
        return ans;
        
    }
};
// 20 30 30 40 40 
// 30 20 20 40 30 
    
//     0 0 0 

// 30 20 30 40 40