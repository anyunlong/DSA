class Solution {
    func reverse(_ x: Int) -> Int {
        var newX = Int64(x)
        var result = Int64(0)
        let max32Int = Int64(Int32.max)
        let min32Int = Int64(Int32.min)
        
        while newX != 0 {
            result *= 10
            if x > 0 {
                if result > max32Int {
                    return 0
                }
                result = newX % 10 + result
                if result > max32Int {
                    return 0
                }
            }
            if x < 0 {
                if result < min32Int {
                    return 0
                }
                result = newX % 10 + result
                if result < min32Int {
                    return 0
                }
            }
            newX /= 10
        }
        
        return Int(result)
    }
}
