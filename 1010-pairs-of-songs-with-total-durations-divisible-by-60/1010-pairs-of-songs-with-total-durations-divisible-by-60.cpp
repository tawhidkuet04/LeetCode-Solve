class Solution {
public:
    int findNum(int lo, int hi, int num, bool isLowerBound, vector<int> & time){
        int ans = - 1;
        while(lo <= hi){
            int mid = lo + ( hi - lo )/2;
            
            if( time[mid] > num){
                hi = mid - 1;
            }else if (time[mid] < num){
                lo = mid + 1;
            }else{
                 ans = mid;
                if(isLowerBound){
                    hi = mid - 1;
                }else{
                    lo = mid + 1;
                }
            }
        }
        return ans;
    }
    
    
    int numPairsDivisibleBy60(vector<int>& time) {
        for(int &num : time){
            num %= 60;
            // cout << num << endl;
        }
        sort(time.begin(), time.end());
        
        int size = time.size(), ans = 0;
        
        
        for(int index = 0; index < size; index ++){
            int lowerBound = findNum(index + 1, size - 1, (60 - time[index]) % 60, true, time);
            if(lowerBound == -1 ){
                continue;
            }
            
            int upperBound = findNum(index + 1, size - 1, (60 - time[index]) % 60, false, time);
            
            ans += (upperBound - lowerBound + 1);
            
            
        }
       
        return ans;
        
    }
};
// 20 30 30 40 40 
// 30 20 20 40 30 
    
//     0 0 0 