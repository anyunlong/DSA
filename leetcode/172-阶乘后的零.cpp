class Solution {
    func trailingZeroes(_ n: Int) -> Int {
        var count = 0
        var num = n
        while num >= 5 {
            count += (num / 5)
            num /= 5
        }
        return count
    }
}
