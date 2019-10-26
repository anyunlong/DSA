class Solution {
    func tenToThreeString(_ n: Int) -> String {
        if n < 1 {
            return ""
        }
        var result = ""
        var dividend = n
        var remainder = 0
        while dividend != 1 {
            var a = false
            var b = false
            remainder = dividend % 3
            if remainder == dividend {
                a = true
            }
            dividend = dividend / 3
            if dividend == 0 {
                b = true
            }
            if a && b {
                return "\(remainder)" + result
            } else {
                result = "\(remainder)" + result
            }
        }
        result = "1" + result
        return result
    }
    
    func isPowerOfThree(_ n: Int) -> Bool {
        if n < 1 {
            return false
        }
        let threeString = tenToThreeString(n)
        var result = false
        for (index, c) in threeString.enumerated() {
            if c == "1" && index == 0 {
                result = true
            } else {
                if c != "0" {
                    return false
                }
            }
        }
        return result
    }
}
