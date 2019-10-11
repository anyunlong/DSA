class Solution {
    func bitSquareSum(_ n: Int) -> Int {
        if n > 0 {
            var varN = n
            var sum = 0
            while varN != 0 {
                let remainder = varN % 10
                sum = remainder * remainder + sum
                varN = varN / 10
            }
            return sum
        } else {
            return 0
        }
    }

    func isHappy(_ n: Int) -> Bool {
        if n > 0 {
            var slow = n
            var fast = bitSquareSum(n)
            while slow != fast {
                slow = bitSquareSum(slow)
                fast = bitSquareSum(fast)
                fast = bitSquareSum(fast)
            }
            if slow == 1 {
                return true
            } else {
                return false
            }
        } else {
            return false
        }
    }
}
