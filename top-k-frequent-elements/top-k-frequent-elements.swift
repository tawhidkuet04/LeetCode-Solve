class Solution {
    
    func partition( _ nums: inout [Int], _ left: Int, _ right: Int) -> Int{
        var pivot = right, left = left, right = right, pIndex = left
        
        for index in left..<right{
            if nums[index] <= nums[pivot]{
                nums.swapAt(index , pIndex)
                pIndex += 1
            }
        }
        nums.swapAt(pIndex, pivot)
        return pIndex
    }
    
    var topKIndex = 0
    func quickSelect( _ nums: inout [Int], _ left: Int, _ right: Int, _ k: Int){
        if left >= right{
            return 
        }
        
        var index = partition( &nums, left, right)
        
        if  index == (nums.count - k){
            topKIndex = index
            return
        }
        
        if index > (nums.count - k){
            quickSelect( &nums, left, index - 1, k)
        }else{
            quickSelect( &nums, index, right, k)
        }
        
    }
    
    
    func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
        var mp = [Int: [Int]]()
        var freqMp = [Int: Int]()
        
        var arr = [Int]()
        
        for num in nums{
            freqMp[ num, default: 0] += 1
        }
        
        for (key, val) in freqMp{
            mp[val, default: []].append(key)
            arr.append(val)
        }
        
        quickSelect( &arr, 0, arr.count - 1, k)
        
        var ans = [Int]()
        print(topKIndex)
        print(arr)
        print(mp)
        
        var vis = [Int: Int]()
        for index in topKIndex..<arr.count{
            print(arr[index])
            if vis[ arr[index], default: 0 ] == 0{
                vis[ arr[index], default: 0 ] = 1
                var val = mp[arr[index], default: []]
            // print(val)
            for num in val{
                ans.append(num)
            }
            if (ans.count == k){
                break
            }
            }
            
        }
        return ans

        
    }
 
}