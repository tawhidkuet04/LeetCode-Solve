class Solution {
public:
    
    void calculateTotalDamage(vector<int>& damage, long long &totalDamage){
        int sz= damage.size();
        
        for(int index = 0; index < sz; index ++ ){
            totalDamage += damage[index];
        }
    }
    
    
    bool isPossible(vector<int> &damage, long long minHealth, int armor){
        
        int sz = damage.size();
        
        // minHealth += (long long)armor;
        
        sort(damage.begin(), damage.end());
        // reverse(damage.begin(), damage.end());
        
        
        for(int index = 0; index < sz; index ++ ){
           if( minHealth > damage[index] ) {
               minHealth -= damage[index];
           }else{
               long long curDamage = 0 ;
               if( armor < damage[index]){
                   curDamage = damage[index] - armor;
               }
               minHealth -= curDamage;
               armor = 0;
           }
           
        }
        
        if(minHealth <= 0) return false;
        else return true;
    }
    
    
    long long minimumHealth(long long start, long long end, vector<int> &damage, int armor){
        
        long long ans = 0;
        
        while(start <= end){
            long long mid = start + (end - start)/2;
            
            if(isPossible(damage, mid, armor)){
                cout << mid << endl;
                ans = mid ;
                end  = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        
        
        return ans;
    }
    
    
    long long minimumHealth(vector<int>& damage, int armor) {
        long long totalDamage = 0 ;
        
        
       
        calculateTotalDamage(damage, totalDamage);
        
         if(armor == 0){
            return totalDamage + 1;
        }
        
        if(totalDamage == 0){
            return 1;
        }
        
        // cout << totalDamage << endl;
        
        return minimumHealth(0, totalDamage, damage, armor);
    }
};