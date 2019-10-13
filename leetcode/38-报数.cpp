class Solution {
    func countAndSay(_ n: Int) -> String {
        if n < 1 || n > 30 {
            return ""
        }
        if n == 1 {
            return "1"
        }
        
        let lastString = countAndSay(n - 1)
        if lastString == "1" {
            return "11"
        }

        var count = 1
        var resultString = ""
        var lastChar = lastString.first!
        for (index, char) in lastString.enumerated() {
            if index == 0 {
                continue
            } else {
                if char == lastChar {
                    count += 1
                } else {
                    resultString.append(contentsOf: "\(count)\(lastChar)")
                    count = 1
                }
            }
            lastChar = char
        }
        resultString.append(contentsOf: "\(count)\(lastChar)")
        
        return resultString
    }
}
