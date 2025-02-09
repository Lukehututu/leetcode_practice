/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int cnt = 1;
        while (!prices.empty() && prices.top().first <= price) {
            cnt += prices.top().second;
            prices.pop();
        }
        //此时栈顶元素刚好是price左侧第一个比它大的元素
        prices.push({ price, cnt });
        return cnt;
    }

    stack<pair<int,int>> prices;

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

