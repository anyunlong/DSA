class Solution {
    func subsets(_ nums: [Int]) -> [[Int]] {
        var resultArray: [[Int]] = [[]]
        
        for num in nums {
            let simpleObjectArray = [num]
            var newArrayWithNum: [[Int]] = []
            for subArray in resultArray {
                newArrayWithNum.append(subArray + simpleObjectArray)
            }
            resultArray += newArrayWithNum
        }
        
        return resultArray
    }
}
