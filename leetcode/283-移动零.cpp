class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        if nums.count == 0 {
            return
        }
        var slowIndex = 0
        for index in 0..<nums.count {
            if nums[index] == 0 {
            } else {
                let temp = nums[index]
                nums[index] = nums[slowIndex]
                nums[slowIndex] = temp
                slowIndex += 1
            }
        }
    }
}