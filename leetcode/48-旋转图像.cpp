class Solution {
    func reverse(_ array: inout [Int]) {
        for index in 0..<array.count/2 {
            let mirrorIndex = array.count - index - 1
            let temp = array[index]
            array[index] = array[mirrorIndex]
            array[mirrorIndex] = temp
        }
    }
    
    func rotate(_ matrix: inout [[Int]]) {
        // 左右翻转
        for (index, _) in matrix.enumerated() {
            reverse(&matrix[index])
        }
        // 正斜杠对角线反转
        for (subArrayIndex, subArray) in matrix.enumerated() {
            for (itemIndex, _) in subArray.enumerated() {
                if subArrayIndex + itemIndex < matrix.count - 1 {
                    let mirrorLocationY = matrix.count - (subArrayIndex + 1)
                    let mirrorLocationX = matrix.count - (itemIndex + 1)
                    let temp = matrix[subArrayIndex][itemIndex]
                    matrix[subArrayIndex][itemIndex] = matrix[mirrorLocationX][mirrorLocationY]
                    matrix[mirrorLocationX][mirrorLocationY] = temp
                }
            }
        }
    }
}
