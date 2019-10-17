class MinStack {

    var array: [Int] = []

    /** initialize your data structure here. */
    init() {
        
    }
    
    func push(_ x: Int) {
        if array.count == 0 {
            array.append(x)
            array.append(x)
        } else {
            let min = getMin()
            if x < min {
                array.append(x)
                array.append(x)
            } else {
                array.append(min)
                array.append(x)
            }
        }
    }
    
    func pop() {
        if array.count == 0 {
            return
        }
        array.removeLast()
        array.removeLast()
    }
    
    func top() -> Int {
        return array.last ?? 0
    }
    
    func getMin() -> Int {
        let count = array.count
        if count == 0 {
            return 0
        } else {
            return array[count - 2]
        }
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack()
 * obj.push(x)
 * obj.pop()
 * let ret_3: Int = obj.top()
 * let ret_4: Int = obj.getMin()
 */
