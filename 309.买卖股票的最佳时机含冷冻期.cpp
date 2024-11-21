/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (64.92%)
 * Likes:    1783
 * Dislikes: 0
 * Total Accepted:    349.9K
 * Total Submissions: 538.3K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
 * 
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 
 * 
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 
 * 
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: prices = [1,2,3,0,2]
 * 输出: 3 
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 * 
 * 示例 2:
 * 
 * 
 * 输入: prices = [1]
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:


    //  回溯最后一个用例跑不过
    // int ans = 0;

    // /*
    //     flag:
    //     0 冷冻了
    //     1 买了
    //     2 卖了
    // */
    // void backTrace(int sum, int i, int flag,vector<int>& prices){
    //     if(i == prices.size()){
    //         ans = max(sum,ans);
    //         return;
    //     }
        
    //     int maxRet = sum + accumulate(prices.begin() + i,prices.end(),0);
    //     if(maxRet <= ans) return;

    //     //  买了 (卖了才能买)
    //     if(flag == 2){
    //         backTrace(sum - prices[i],i + 1, 1 ,prices);
    //         //  可以买但不买
    //         backTrace(sum,i + 1, 2 ,prices);
    //     }
    //     else if(flag == 1){
    //         backTrace(sum + prices[i],i + 1,0,prices);
    //         //  可以卖，但选择不卖
    //         backTrace(sum,i + 1,1,prices);
    //     }
    //     //  冷冻了，直接下一次
    //     else if(flag == 0){
    //         backTrace(sum,i + 1,2,prices);
    //     }
      

    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int prev_froze = 0;
        int hold = -prices[0];
        int sell = 0;

        for (int i = 1; i < n; ++i) {
            int new_froze = hold + prices[i]; // 使用旧的 hold 计算 froze
            hold = max(hold, sell - prices[i]);
            sell = max(sell, prev_froze);     // 使用旧的 froze 计算 sell
            prev_froze = new_froze;           // 更新 prev_froze
        }
        return max(sell, prev_froze);

        
    }
};
// @lc code=end

