"""
方法一：用2个变量记录当前的最大收益和股票的最低值，遍历数组，不断更新最大收益和股票最低值(收益=卖出价格-买入价格，显然卖出价格越高或买入价格越低，收益越高)
(其实这种方法也就是优化后的动态规划方法)
"""
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        minprice = 1e9
        maxprofit = 0
        for price in prices:
            maxprofit = max(maxprofit, price - minprice)
            minprice = min(minprice, price)
        return int(maxprofit)


if __name__ == '__main__':
    price = [7,1,5,3,6,4]
    obj = Solution()
    result = obj.maxProfit(price)
    print(result)
