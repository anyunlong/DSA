class Solution {
    func isAnagram(_ s: String, _ t: String) -> Bool {
        if s.count != t.count {
            return false
        }

        if s == "" && t == "" {
            return true
        }
        
        var dict = [Character : Int]()
        for c in s {
            if let value = dict[c] {
                dict[c] = value + 1
            } else {
                dict[c] = 1
            }
        }

        for c in t {
            if let value = dict[c] {
                dict[c] = value - 1
                if value - 1 < 0 {
                    return false
                }
            } else {
                return false
            }
        }

        return true
    }
}