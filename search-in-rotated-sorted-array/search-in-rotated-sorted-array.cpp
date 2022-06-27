class Solution {
public:
    
    int getRotatedIndex(int lo, int hi, vector<int>& nums){
        while(lo < hi){
            int mid = (lo + hi )/2;
            cout << lo << " " << hi << endl;
            if(lo == mid){
                 break;
            }
            if(nums[lo] < nums[mid]){
                lo = mid ;
            }else if( nums[lo] > nums[mid]){
                hi = mid ;
            }
        }
        
        return lo;
    }
    
    int bin(int lo, int hi, vector<int>& nums, int target){
        int ans = -1;
        
        while(lo <= hi){
            int mid = (lo + hi )/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        return ans;
    }
    
    int search(vector<int>& nums, int target) {
        
        if(nums[0] < nums[nums.size() - 1]){
            return bin(0, nums.size() - 1, nums, target);
        } 
        int rotate =  getRotatedIndex(0, nums.size() - 1, nums);
        
        int left = bin(0, rotate, nums, target);
        
        if(left != -1) return left;
        
        return bin(rotate + 1, nums.size() - 1, nums, target);
    }
};


// 6,7,8, 9, 19, 0 ,1,2,3, 4, 5