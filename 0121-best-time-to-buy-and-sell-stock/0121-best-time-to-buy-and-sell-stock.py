class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy_val = float("inf")
        profit = -1
        for val in prices:
            if buy_val > val:
                buy_val = val
            if val > buy_val:
                # print("b", buy_val)
                # print("v", val)
                p = val - buy_val
                # print("p", p)
                if p > profit:
                    profit = p
        if profit != -1:
            return profit
        else:
            return 0
            