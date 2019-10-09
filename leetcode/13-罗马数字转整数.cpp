class Solution {
    func romanToInt(_ s: String) -> Int {
        var sum = 0
        var lastChar = ""
        var mutableString = s
        while (true) {
            if mutableString == "" {
                break
            }
            let char = mutableString.popLast()
            let popedChar = String(char!)
            if popedChar == "I" {
                if lastChar == "V" || lastChar == "X" {
                    sum = sum - 1
                } else {
                    sum = sum + 1
                }
            } else if popedChar == "V" {
                sum = sum + 5
            } else if popedChar == "X" {
                if lastChar == "L" || lastChar == "C" {
                    sum = sum - 10
                } else {
                    sum = sum + 10
                }
            } else if popedChar == "L" {
                sum = sum + 50
            } else if popedChar == "C" {
                if lastChar == "D" || lastChar == "M" {
                    sum = sum - 100
                } else {
                    sum = sum + 100
                }
            } else if popedChar == "D" {
                sum = sum + 500
            } else if popedChar == "M" {
                sum = sum + 1000
            } else {
                // 进不来，因为 认为输入值没有罗马数字之外的字符
            }
            lastChar = popedChar
        }
        return sum
    }
}
