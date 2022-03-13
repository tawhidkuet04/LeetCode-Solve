class Solution {
    func findKthLargest(_ nums: [Int], _ k: Int) -> Int {
        var heap = Heap<Int>{ $0 > $1}
 
        for num in nums{
           heap.push(num)
          
        }
        
        var count = 0
        var ans = 0
        // print(heap.arr)
        
        while( count < k){
            var peek = heap.top()!
            heap.pop()
            count += 1
            ans = peek
            // print(ans)
        }
        return ans
    }
    
    
    
       struct Heap<Element>{
    
    var arr = [Element]()
    
    var compare : (Element,Element) -> Bool

    
    func getLeftChildIndex(index: Int) -> Int {
        return 2 * index + 1
    }
    
    func getRightChildIndex(index: Int) -> Int {
        return 2 * index + 2
    }
    
    func getParentIndex(index: Int) -> Int {
        return (index - 1)/2
    }
    
    
    func hasLeftChild(index: Int) -> Bool {
        return getLeftChildIndex(index: index) < arr.count
    }
    
    func hasRightChild(index: Int) -> Bool {
        return getRightChildIndex(index: index) < arr.count
    }
    
    func hasParent(index: Int) -> Bool {
        return getParentIndex(index: index) >= 0
    }
    
    
    func getLeftChild(index: Int) -> Element {
        return arr[getLeftChildIndex(index: index)]
    }
    
    func getRightChild(index: Int) -> Element {
        return arr[getRightChildIndex(index: index)]
    }
    
    func getParent(index: Int) -> Element {
        return arr[getParentIndex(index: index)]
        
    }
    
    public mutating func push(_ value: Element)  {
        arr.append(value)
        heapifyUp()
    }
    
    public mutating func pop(){
        guard arr.count != 0 else{
            return
        }
        arr.swapAt(0, arr.count - 1)
        arr.removeLast()
        heapifyDown()
        
    }
    
    public mutating func heapifyUp(){
        
        var index = arr.count - 1
        while(hasParent(index: index) && getComparision(first:  arr[index], second: getParent(index: index))){
            arr.swapAt(index, getParentIndex(index: index))
            index = getParentIndex(index: index)
        }
        
    }
    
    public func top() -> Element?{
        return arr.first
    }
    
    public mutating func heapifyDown(){
        var index = 0
        var leftChild: Int = 0
        var rightChild: Int = 0
     
        while( hasLeftChild(index: index) ){
//            print("sd \(index)")
            if hasLeftChild(index: index){
                leftChild = getLeftChildIndex(index: index)
            }
            if hasRightChild(index: index){
                rightChild = getRightChildIndex(index: index)
                
               
                if  getComparision(first: getRightChild(index: index), second: getLeftChild(index: index)) {
                    leftChild = rightChild
                }
                
            }
            
            if  getComparision (first: arr[leftChild] , second:  arr[index]){
                arr.swapAt(index, leftChild)
            }else{
                break
            }
            index = leftChild
        }
        
    }
    
    
        public func getComparision(first: Element, second: Element) -> Bool {
            return compare(first, second)
        } 
  }
}