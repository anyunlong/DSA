class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        if nums.count == 0 {
            return 0
        }
        if nums.count == 1 {
            return 1
        }
        
        var newArrayIndex = 0
        for index in 1..<nums.count {
            if nums[index] > nums[newArrayIndex] {
                newArrayIndex += 1
                nums[newArrayIndex] = nums[index]
            } else {
                continue
            }
        }
        return newArrayIndex + 1
    }
}
