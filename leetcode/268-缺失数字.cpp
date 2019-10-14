class Solution {
    func missingNumber(_ nums: [Int]) -> Int {
        var sum = (nums.count + 1) * nums.count / 2
        for num in nums {
            sum -= num
        }
        return sum
    }
}
