/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */
class Solution {
    func reverseList(_ head: ListNode?) -> ListNode? {
        guard let head = head else {
            return nil
        }
        
        var lastNode: ListNode?
        var currentNode: ListNode = head
        var nextNode = head.next
        while let newNextNode = nextNode {
            currentNode.next = lastNode
            lastNode = currentNode
            currentNode = newNextNode
            nextNode = newNextNode.next
        }
        currentNode.next = lastNode
        return currentNode
    }
    
    func compareTwoListPrefix(_ first: ListNode?, _ second: ListNode?) -> Bool {
        var mutableFirst = first
        var mutableSecond = second
        while let a = mutableFirst,
            let b = mutableSecond {
            if a.val != b.val {
                return false
            }
            mutableFirst = a.next
            mutableSecond = b.next
        }
        return true
    }
    
    func isPalindrome(_ head: ListNode?) -> Bool {
        guard let head = head,
            let headNext = head.next else {
            return true
        }
        var fast = headNext
        var slow = head
        while let fastNext = fast.next {
            slow = slow.next!
            fast = fastNext
            if let fastNext = fast.next {
                fast = fastNext
            }
        }
        var rightList: ListNode?
        var leftList: ListNode?
        leftList = head
        rightList = reverseList(slow.next)
        slow.next = nil
        return compareTwoListPrefix(leftList, rightList)
    }
}
