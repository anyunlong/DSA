// 贪心算法得到的是最优解，但只是凑巧罢了。取折线图的所有上升线是对的
class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        var max = 0
        for index in 0..<prices.count {
            if (index + 1) == prices.count {
                return max
            }
            if prices[index + 1] > prices[index] {
                max = prices[index + 1] - prices[index] + max
            }
        }
        
        return max
    }
}
