class Node {
    let value: Character
    var left: Node?
    var right: Node?
    
    init(_ value: Character) {
        self.value = value
    }
}

class Solution {
    func newFunc(string: String, resultArray: inout [String], _ node: Node?, _ currentDepth: Int, _ n: Int, sum: Int, leftCount: Int) {
        guard let node = node else {
            return
        }
        if n <= 0 {
            return
        }
        if currentDepth <= 0 {
            return
        }
        if currentDepth > 2 * n {
            return
        }
        if sum < 0 {
            return
        }
        if leftCount > n || leftCount < 0 {
            return
        }
        
        var newString = ""
        if leftCount < n {
            node.left = Node("(")
            newString = "\(string)("
            newFunc(string: newString, resultArray: &resultArray, node.left, currentDepth + 1, n, sum: sum + 1, leftCount: leftCount + 1)
        }
        if sum > 0 {
            node.right = Node(")")
            newString = "\(string))"
            newFunc(string: newString, resultArray: &resultArray, node.right, currentDepth + 1, n, sum: sum - 1, leftCount: leftCount)
        }
        if newString.count == 2 * n {
            resultArray.append(newString)
        }
    }

    func generateParenthesis(_ n: Int) -> [String] {
        if n <= 0 {
            return []
        }
        
        var resultArray: [String] = []
        newFunc(string: "(", resultArray: &resultArray, Node("("), 1, n, sum: 1, leftCount: 1)
        
        return resultArray
    }
}
