class Solution {
    func getSum(_ a: Int, _ b: Int) -> Int {
        var a1 = a
        var b1 = b
        var temp = 0
        while b1 != 0 {
            temp = a1 ^ b1
            b1 = (a1 & b1) << 1
            a1 = temp
        }
        return a1
    }
}
