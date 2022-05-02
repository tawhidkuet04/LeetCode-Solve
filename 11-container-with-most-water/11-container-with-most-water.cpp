class Solution {
public:
    int maxArea(vector<int>& height) {
         int ans = 0, size = height.size(), left = 0, right = size - 1;
        
        while(left <= right){
            ans = max(ans , (right - left) * min(height[left], height[right]));
            
            if(height[right] > height[left]){
                left ++ ;
            }else {
                right --;
            }
        }
        return ans;
    }
};

// 1,8,6,2,5,4,8,3,7
    
// 8 