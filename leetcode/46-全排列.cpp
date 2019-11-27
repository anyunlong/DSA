class Solution {
    func permute(_ nums: [Int]) -> [[Int]] {
        var resultArray: [[Int]] = [[]]
        for num in nums {
            var newArray: [[Int]] = [] // 空数组准备好了
            for subArray in resultArray { // 遍历记录的数组，准备往上面填数据
                if subArray.count == 0 {
                    newArray.append([num])
                } else {
                    for index in 0..<(subArray.count + 1) {
                        let reversedIndex = subArray.count - index
                        var mutableSubArray = subArray
                        mutableSubArray.insert(num, at: reversedIndex)
                        newArray.append(mutableSubArray)
                    }
                }
            }
            resultArray.removeAll()
            resultArray += newArray
        }
        
        return resultArray
    }
}
