class Solution {
public:
    
    void storeFreqCount(vector<int> & arr, int mp[]){
        for(int index = 0; index < arr.size(); index ++ ){
            mp[arr[index]] ++ ;
        }
    }
    
    int threeSumMulti(vector<int>& arr, int target) {
        int mp[500] = {0};
        
        const int mod = 1000000007;
        
        int sz = arr.size();
        
        storeFreqCount(arr, mp);
        
        int ans = 0 ;
        
        for(int index1 = 0; index1 < sz; index1 ++ ){
            mp[arr[index1]] --;
            for(int index2 = index1 + 1; index2 < sz - 1; index2 ++ ){
                mp[arr[index2]] -- ;
                
                int rem = target - (arr[index1] + arr[index2]);

                if( rem >= 0 ){
                     ans = ( ans % mod + mp[rem] % mod ) % mod;
                }
               
                
            }
            
           for(int index2 = index1 + 1; index2 < sz - 1; index2 ++ ){
                mp[arr[index2]] ++;
           }
        }
        
        
        return ans;
    }
};