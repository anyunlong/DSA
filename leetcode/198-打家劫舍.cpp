class Solution {
    func rob(_ nums: [Int]) -> Int {
        if nums.count == 0 {
            return 0
        }
        if nums.count == 1 {
            return nums[0]
        }
        if nums.count == 2 {
            return (nums[0] > nums[1]) ? nums[0] : nums[1]
        }
        var array: [Int] = [nums[0], (nums[0] > nums[1]) ? nums[0] : nums[1]]
        for (index, num) in nums.enumerated() {
            if index == 0 || index == 1 {
                continue
            }
            let rightToLeftSecond = array[array.count - 2]
            let last = array.last!
            array.append(((rightToLeftSecond + num) > last) ? (rightToLeftSecond + num) : last)
        }
        return array.last!
    }
}
