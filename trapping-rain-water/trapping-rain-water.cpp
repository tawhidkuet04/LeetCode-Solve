class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, size = height.size(), left = 0, right = size - 1,
        leftMax = 0, rightMax = 0 ;
        
        while(left <= right){
            if(height[left] <= height[right]){
                if(leftMax > height[left]){
                    ans += leftMax - height[left];
                }else{
                    leftMax = height[left];
                }
                left ++;
            }else{
                 if(rightMax > height[right]){
                    ans += rightMax - height[right];
                }else{
                    rightMax = height[right];
                }
                right --;
            }
            
        }
        
        return ans;
        
    }
};


// 9 5 2 6

// 0,1,0,2,1,0,1,3,2,1,2,1
// 5 3 2 
    
    