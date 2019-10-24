class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        var array: [Int] = []
        var index1 = 0
        var index2 = 0
        while index1 != m && index2 != n {
            if nums1[index1] < nums2[index2] {
                array.append(nums1[index1])
                index1 += 1
            } else {
                array.append(nums2[index2])
                index2 += 1
            }
        }
        if index1 == m {
            for newIndex2 in index2..<n {
                array.append(nums2[newIndex2])
            }
        }
        if index2 == n {
            for newIndex1 in index1..<m {
                array.append(nums1[newIndex1])
            }
        }
        
        for index in 0..<array.count {
            nums1[index] = array[index]
        }
    }
}
