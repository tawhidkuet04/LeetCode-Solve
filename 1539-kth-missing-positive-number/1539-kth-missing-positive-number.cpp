class Solution {
public:
    int findMissingNum(int lo, int hi, vector<int> &arr, int &k){
        int pos = 0;
        
        if(arr[0] != 1 && k < arr[0]){
            return k;
        }
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int kValueLessThanCurPos  = (arr[mid] - mid - 1);
            cout << mid << " " << kValueLessThanCurPos <<endl;
            if(  kValueLessThanCurPos < k ){
                pos = mid;
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        cout << pos;
        int missingNumCount =  k - (arr[pos] - pos - 1); 
        int ans = arr[pos] + missingNumCount;
        return ans;
    }
    
    int findKthPositive(vector<int>& arr, int k) {
       int size = arr.size() - 1;
       return findMissingNum(0, size , arr, k );
        
    }
};

// 7 2 3 4 11

// 1 2 3
    
//     2 - 1 - 1
    
//     1 - 0 - 1