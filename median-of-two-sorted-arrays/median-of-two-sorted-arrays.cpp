class Solution {
public:
    
    double find(vector<int>& nums1, vector<int>& nums2){
       
        
        if(nums1.size() > nums2.size()) return find(nums2, nums1);
        
        int n1 = nums1.size(), n2 = nums2.size();
        
        int lo = 0, hi = n1;
        
        
        while(lo <= hi) {
           
            int chunk1 = (lo + hi ) / 2;
            int chunk2 = (n1 + n2 + 1)/ 2 - chunk1;
            cout << lo << " "<< hi << endl;
            int left1 = (chunk1 == 0) ? INT_MIN : nums1[chunk1-1];
            int left2 = (chunk2 == 0) ? INT_MIN : nums2[chunk2 - 1];
            
            int right1 = (chunk1 == n1) ? INT_MAX : nums1[chunk1];
            int right2 = (chunk2 == n2) ? INT_MAX : nums2[chunk2];
            
            
            if(left1 <= right2 && left2 <= right1){
                if( (n1 + n2) % 2 == 0){
                    return (double)(max(left1, left2) + min(right1, right2))/ 2.0;
                }else{
                    return max(left1, left2);
                }
            }else if (left1 > right2){
                hi = chunk1 - 1;
            }else{
                
                lo = chunk1 + 1;
                // cout << lo << endl;
            }
            
        }
        
        return 0.0;
        
        
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        return find(nums1, nums2);
    }
};