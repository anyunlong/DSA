class Solution {
    func intersect(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        var dict: [Int : Int] = [:]
        for num in nums1 {
            if let count = dict[num] {
                dict[num] = count + 1
            } else {
                dict[num] = 1
            }
        }
        var result: [Int] = []
        for num in nums2 {
            if let count = dict[num] {
                if count > 0 {
                    result.append(num)
                }
                dict[num] = count - 1
            }
        }
        
        return result
    }
}
