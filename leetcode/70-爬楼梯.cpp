class Solution {
    var dict: [Int : Int] = [:]
    
    func climbStairs(_ n: Int) -> Int {
        if let value = dict[n] {
            return value
        }
        
        if n == 1 {
            return 1
        }
        if n == 2 {
            return 2
        }
        
        let result = climbStairs(n - 1) + climbStairs(n - 2)
        dict[n] = result
        return result
    }
}
