class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int size = s.size();
        
        if(size == 1){
            return 0;
        }
        
        int leftChange = 0, rightChange = 0, ans = INT_MAX;
        
        for(int index = 0; index < size - 1; index ++){
            if(s[index] == '1')  leftChange++;
        }
        
        int leftIndex = size - 2, rightIndex = size - 1;
        ans = leftChange + rightChange;
        while(rightIndex > 0){
            if(s[leftIndex] == '1') leftChange -- ;
            if(s[rightIndex] == '0') rightChange ++ ;
            
            ans = min(ans, leftChange +  rightChange);
            leftIndex -- ;
            rightIndex -- ;
        }
        
        return ans;
        
    }
};