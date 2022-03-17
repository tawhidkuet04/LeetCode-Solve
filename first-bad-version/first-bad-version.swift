/**
 * The knows API is defined in the parent class VersionControl.
 *     func isBadVersion(_ version: Int) -> Bool{}
 */

class Solution : VersionControl {
    func firstBadVersion(_ n: Int) -> Int {
        var lo = 1, hi = n, ans = 0
        
        while(lo <= hi){
            var mid = lo + ( hi - lo ) / 2
            
            if !isBadVersion(mid){
                lo = mid + 1
            }else{
                ans = mid 
                hi = mid - 1
            }
        }
        return ans
        
    }
}