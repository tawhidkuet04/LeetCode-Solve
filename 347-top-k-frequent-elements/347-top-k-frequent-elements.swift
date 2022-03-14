class Solution {
    
    func partition( _ nums: inout [Int], _ left: Int, _ right: Int, _ mp: [Int: Int]) -> Int{
        var pivot = left +  ((Int.random(in: 0...nums.count)) % (right - left + 1)), left = left, right = right, pIndex = left
        print(pivot)
        let pivotFreq = mp[nums[pivot], default:0]
        nums.swapAt(pivot, right)
        for index in stride(from: left, to: right, by: 1){
            if mp[nums[index], default:0] < pivotFreq{
                nums.swapAt(index , pIndex)
                pIndex += 1
            }
        }
        nums.swapAt(right, pIndex)
        return pIndex
    }
    
    var topKIndex = 0
    func quickSelect( _ nums: inout [Int], _ left: Int, _ right: Int, _ k: Int, _ mp: [Int: Int]){
        if left >= right{
            return 
        }
        
        var index = partition( &nums, left, right, mp)
        
        if  index == (nums.count - k){
            topKIndex = index
            return
        }else if index > (nums.count - k){
            quickSelect( &nums, left, index - 1, k, mp)
        }else{
            quickSelect( &nums, index + 1, right, k, mp)
        }
        
    }
    
    
    func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
        var freqMp = [Int: Int]()
        
        for num in nums{
            freqMp[ num, default: 0] += 1
        }
        
        var arr = [Int]()
        for (key,val) in freqMp{
            arr.append(key)
        }
        
        quickSelect( &arr, 0, arr.count - 1, k, freqMp)
        
        var ans = [Int]()
        
        for index in (arr.count - k)..<arr.count{
            ans.append(arr[index])
        }
        
        
        return ans

        
    }
 
}