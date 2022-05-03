class Solution {
public:
    
    
    void twoSum(vector<int> &nums, int left, int target, int &closet, int &ans){
        int right = nums.size() - 1;
        int size = nums.size();
        int start = left - 1;
        
        while(left < right ){
            int sum = nums[left] + nums[right] + nums[start];
            int diff = abs(target - sum);
            
            if(closet >= diff){
                closet = diff;
                ans = sum;
            }
            
            if( target > sum){
                left ++;
            }else {
                right --;
            }
            
            
        }
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int closet = INT_MAX, ans = 0;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int index = 0; index <= size - 3; index ++  ){
            twoSum(nums, index + 1, target, closet, ans);
            cout << closet << endl;
        }
        return ans;
    }
};

// -1,2,1,-4
// - 4 - 1 1 2
    
    
    
//     4 
    
//     -5 + 1
// -3 0 1 2
    
//     1+ 5