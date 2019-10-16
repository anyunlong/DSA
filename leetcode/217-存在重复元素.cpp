class Solution {
    func containsDuplicate(_ nums: [Int]) -> Bool {
        var dict: [Int : Int] = [:]
        for num in nums {
            if let _ = dict[num] {
                return true
            }
            dict[num] = num
        }
        return false
    }
}
