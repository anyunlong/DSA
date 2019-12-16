class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dict: [Int : Int] = [:]
        for index in 0..<nums.count {
            if let value = dict[target - nums[index]] {
                return [value, index]
            }
            
            dict[nums[index]] = index
        }
        
        return [-1, -1]
    }
}
