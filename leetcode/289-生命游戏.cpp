class Solution {
    // 0-0 -2
    // 0-1 -1
    // 1-0 2
    // 1-1 3
    func gameOfLife(_ board: inout [[Int]]) {
        for (index1, subArray) in board.enumerated() {
            for (index2, _) in subArray.enumerated() {
                convert(&board, index1, index2)
            }
        }
        
        for (index1, subArray) in board.enumerated() {
            for (index2, _) in subArray.enumerated() {
                switch board[index1][index2] {
                case -2, 2:
                    board[index1][index2] = 0
                case -1, 3:
                    board[index1][index2] = 1
                default:
                    print("default")
                }
            }
        }
    }
    
    func isLivingNum(_ num: Int) -> Bool {
        if num == 1 || num == 2 || num == 3 {
            return true
        } else {
            return false
        }
    }
    
    func convert(_ board: inout [[Int]], _ index1: Int, _ index2: Int) {
        if index1 >= 0 && index2 >= 0 {
            if board.count > index1 && board[index1].count > index2 {
                var livingCellCount = 0
                let left = index2 - 1
                let right = index2 + 1
                let up = index1 - 1
                let down = index1 + 1
                // 左
                if left >= 0 {
                    if isLivingNum(board[index1][left]) {
                        livingCellCount += 1
                    }
                }
                // 上
                if up >= 0 {
                    if isLivingNum(board[up][index2]) {
                        livingCellCount += 1
                    }
                }
                // 右
                if right < board[index1].count {
                    if isLivingNum(board[index1][right]) {
                        livingCellCount += 1
                    }
                }
                // 下
                if down < board.count {
                    if isLivingNum(board[down][index2]) {
                        livingCellCount += 1
                    }
                }
                // 左 上
                if left >= 0 && up >= 0 {
                    if isLivingNum(board[up][left]) {
                        livingCellCount += 1
                    }
                }
                // 左 下
                if left >= 0 && down < board.count {
                    if isLivingNum(board[down][left]) {
                        livingCellCount += 1
                    }
                }
                // 右 上
                if right < board[index1].count && up >= 0 {
                    if isLivingNum(board[up][right]) {
                        livingCellCount += 1
                    }
                }
                // 右 下
                if right < board[index1].count && down < board.count {
                    if isLivingNum(board[down][right]) {
                        livingCellCount += 1
                    }
                }
                
                if board[index1][index2] == 1 { // 活
                    if livingCellCount < 2 || livingCellCount > 3 {
                        board[index1][index2] = 2
                    } else {
                        board[index1][index2] = 3
                    }
                } else { // 死
                    if livingCellCount == 3 {
                        board[index1][index2] = -1
                    } else {
                        board[index1][index2] = -2
                    }
                }
            }
        }
    }
}
