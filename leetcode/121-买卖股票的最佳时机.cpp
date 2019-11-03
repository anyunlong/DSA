class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        if prices.count < 2 {
            return 0
        }
        if prices.count == 2 {
            return (prices[1] > prices[0]) ? (prices[1] - prices[0]) : 0
        }
        var lowest = (prices[1] > prices[0]) ? prices[0] : prices[1]
        var lastMaxProfit = (prices[1] > prices[0]) ? (prices[1] - prices[0]) : 0
        var maxProfit = 0
        for (index, price) in prices.enumerated() {
            if index < 2 {
                continue
            }
            maxProfit = ((price - lowest) > lastMaxProfit) ? (price - lowest) : lastMaxProfit
            lastMaxProfit = maxProfit
            if price < lowest {
                lowest = price
            }
        }
        return maxProfit
    }
}
