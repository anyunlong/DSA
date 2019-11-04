class Solution {
    func maxSubArray(_ nums: [Int]) -> Int {
        if nums.count == 0 {
            return 0
        }
        let middle = nums.count / 2
        var leftSum = 0
        for index in 0..<middle {
            leftSum += nums[index]
            if leftSum < 0 {
                leftSum = 0
            }
        }
        var rightSum = 0
        var index = nums.count - 1
        while middle < index {
            rightSum += nums[index]
            if rightSum < 0 {
                rightSum = 0
            }
            index -= 1
        }
        let middleSubArray = leftSum + rightSum + nums[middle]
        var leftSubArray = 0
        var rightSubArray = 0
        if middle == 0 && middle == (nums.count - 1) {
            return nums[middle]
        } else if middle == 0 && middle != (nums.count - 1) {
            rightSubArray = maxSubArray(Array(nums[(middle + 1)...(nums.count - 1)]))
            return (middleSubArray > rightSubArray) ? middleSubArray : rightSubArray
        } else if middle != 0 && middle == (nums.count - 1) {
            leftSubArray = maxSubArray(Array(nums[0...(middle - 1)]))
            return (middleSubArray > leftSubArray) ? middleSubArray : leftSubArray
        } else {
            leftSubArray = maxSubArray(Array(nums[0...(middle - 1)]))
            rightSubArray = maxSubArray(Array(nums[(middle + 1)...(nums.count - 1)]))
        }
        leftSubArray = (leftSubArray > rightSubArray) ? leftSubArray : rightSubArray
        leftSubArray = (leftSubArray > middleSubArray) ? leftSubArray : middleSubArray
        return leftSubArray
    }
}
