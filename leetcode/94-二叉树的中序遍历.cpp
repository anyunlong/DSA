// Definition for a binary tree node.
// public class TreeNode {
//     public var val: Int
//     public var left: TreeNode?
//     public var right: TreeNode?
//     public init(_ val: Int) {
//         self.val = val
//         self.left = nil
//         self.right = nil
//     }
// }

class Stack {
    var nums: [TreeNode] = []
    
    func top() -> TreeNode? {
        return nums.last
    }
    
    func pop() -> TreeNode? {
        return nums.popLast()
    }
    
    func push(_ num: TreeNode) {
        nums.append(num)
    }
    
    func empty() -> Bool {
        return nums.count == 0
    }
}

class Solution {
    func inorderTraversal(_ root: TreeNode?) -> [Int] {
        var mutableRoot = root
        var result: [Int] = []
        let stack = Stack()
        while let root = mutableRoot {
            stack.push(root)
            if let rootLeft = root.left {
                mutableRoot = rootLeft
            } else {
                var hasRight = false
                while !stack.empty() {
                    let poped = stack.pop()
                    result.append(poped!.val)
                    
                    if let popedRight = poped!.right {
                        mutableRoot = popedRight
                        hasRight = true
                        break
                    }
                }
                if !hasRight {
                    mutableRoot = nil
                }
            }
        }
        return result
    }
}
