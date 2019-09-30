class Solution {
    func majorityElement(_ nums: [Int]) -> Int {
        var majority = nums[0]
        var total = 0
        for num in 0..<nums.count {
            if nums[num] == majority {
                total += 1
            } else {
                total -= 1
                if total == 0 {
                    majority = nums[num + 1]
                }
            }
        }
        
        return majority
    }
}
