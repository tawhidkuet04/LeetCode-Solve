class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stSmall, stLarge;
        
        int sz = nums.size();
        int mnArr[200005] = {0};
        
        mnArr[0] = nums[0];
        
        for(int index = 1;index < sz; index ++){
            mnArr[index] = min(mnArr[index -1 ], nums[index]);
        }
        
        for(int index = 0; index < sz; index ++){

            while(!stLarge.empty() && nums[index] >= nums[stLarge.top()]){
                stLarge.pop();
            }
           
            if(!stLarge.empty()){
                int large = stLarge.top();
                
                if(mnArr[large] != nums[large] && mnArr[large] < nums[index]  ){
                    return true;
                }
            }
            stLarge.push(index);
            
         
            // stLarge.push(index);
        }
        
        return false;
    }
};


// small -  1 2
    
// large -  42 

// i < j < k

//  i j  k 
 

// 3 1 4 2

// inf inf inf inf
// //      1.  1.  1
    
// // 3 4 0 6 0 5
//    3 3 0 0 0 0 

//    - 0  0  - -


// 3



