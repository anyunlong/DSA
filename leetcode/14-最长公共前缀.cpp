class Solution {
    func longestCommonPrefix(_ strs: [String]) -> String {
        if strs.count == 0 {
            return ""
        }
        var commonPrefix = strs.first!
        
        for str in strs {
            commonPrefix = str.commonPrefix(with: commonPrefix)
            if commonPrefix == "" {
                return ""
            }
        }
        
        return commonPrefix
    }
}
