class Solution {
    func firstUniqChar(_ s: String) -> Int {
        var array: [(Character, Int)] = []
        var dict: [Character : UInt] = [:]
        for (index, c) in s.enumerated() {
            if let value = dict[c] {
                dict[c] = value + 1
            } else {
                array.append((c, index))
                dict[c] = 1
            }
        }
        for tuple in array {
            if let value = dict[tuple.0],
                value == 1 {
                return tuple.1
            }
        }
        return -1
    }
}
