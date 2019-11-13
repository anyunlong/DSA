class Solution {
    func findSqrt(_ left: Int , _ right: Int, _ x: Int) -> Int {
        let middle = (left + right) / 2 // 中间或左边
        if (middle * middle) > x { // 取左边
            if left >= (middle - 1) {
                return left
            }
            return findSqrt(left, middle - 1, x)
        } else if (middle * middle) < x { // 取右边
            if (middle + 1) >= right {
                if right * right > x {
                    return middle
                } else {
                    return right
                }
            }
            let middleNext = middle + 1
            if middleNext * middleNext > x {
                return middle
            }
            return findSqrt(middle + 1, right, x)
        } else {
            return middle
        }
    }
    
    func mySqrt(_ x: Int) -> Int {
        return findSqrt(0, x, x)
    }

    
    func isPrime(_ n: Int) -> Bool {
        if n < 2 {
            return false
        }
        if n == 2 || n == 3 {
            return true
        }
        
        let nSqrt = mySqrt(n)
        
        for num in 2...nSqrt {
            if n % num == 0 {
                return false
            }
        }
        return true
    }
    
    func countPrimes(_ n: Int) -> Int {
        var count = 0
        if n < 3 {
            return count
        }
        
        for num in 2...(n - 1) {
            if isPrime(num) {
                count += 1
            }
        }
        
        return count
    }
}
