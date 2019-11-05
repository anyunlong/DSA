class Solution {
    func isValid(_ s: String) -> Bool {
        let dictLeft: [Character : Character] = ["{" : "}",
                                                 "(" : ")",
                                                 "[" : "]"]
        
        let dictRight: [Character : Character] = ["}" : "{",
                                                  ")" : "(",
                                                  "]" : "["]
        var array: [Character] = []
        for c in s {
            if let _ = dictLeft[c] {
                array.append(c)
            } else if let value = dictRight[c] {
                if let last = array.last,
                    value == last {
                    array.removeLast()
                } else {
                    return false
                }
            } else {
                return false
            }
        }
        return array.count == 0
    }
}
