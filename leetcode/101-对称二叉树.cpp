/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
class Solution {
    func copyTree(_ root: TreeNode?) -> TreeNode? {
        if let root = root {
            let newNode = TreeNode(root.val)
            newNode.left = copyTree(root.left)
            newNode.right = copyTree(root.right)
            return newNode
        } else {
            return nil
        }
    }

    func reverse(_ root: TreeNode?) -> TreeNode? {
        let copy = copyTree(root)
        
        if let newRoot = copy {
            let temp = reverse(newRoot.left)
            newRoot.left = reverse(newRoot.right)
            newRoot.right = temp
            return newRoot
        } else {
            return nil
        }
    }

    func isEquals(_ first: TreeNode?, _ second: TreeNode?) -> Bool {
        if first == nil, second == nil {
            return true
        }
        if first?.val == second?.val {
            return isEquals(first?.left, second?.left) && isEquals(first?.right, second?.right)
        } else {
            return false
        }
    }

    func isSymmetric(_ root: TreeNode?) -> Bool {
        let reversed = reverse(root)
        return isEquals(root, reversed)
    }
}
