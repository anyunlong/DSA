class Solution {
    func generate(_ numRows: Int) -> [[Int]] {
        if (numRows < 1) {
            return []
        }

        if (numRows == 1) {
            return [[1]]
        }
        if (numRows == 2) {
            return [[1], [1, 1]]
        }

        var arrayOfArrays = [[1], [1, 1]]
        for colIndex in 2..<numRows {
            var rowArray = [1]
            for rowIndex in 1..<(colIndex + 1) {
                if rowIndex == colIndex {
                    rowArray.append(1)
                } else {
                    rowArray.append(arrayOfArrays[colIndex - 1][rowIndex] + arrayOfArrays[colIndex - 1][rowIndex - 1])
                }
            }
            arrayOfArrays.append(rowArray)
        }
        
        return arrayOfArrays
    }
}
