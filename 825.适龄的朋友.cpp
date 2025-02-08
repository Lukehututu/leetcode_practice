/*
 * @lc app=leetcode.cn id=825 lang=cpp
 *
 * [825] 适龄的朋友
 *
 * https://leetcode.cn/problems/friends-of-appropriate-ages/description/
 *
 * algorithms
 * Medium (45.59%)
 * Likes:    259
 * Dislikes: 0
 * Total Accepted:    53.1K
 * Total Submissions: 112.5K
 * Testcase Example:  '[16,16]'
 *
 * 在社交媒体网站上有 n 个用户。给你一个整数数组 ages ，其中 ages[i] 是第 i 个用户的年龄。
 * 
 * 如果下述任意一个条件为真，那么用户 x 将不会向用户 y（x != y）发送好友请求：
 * 
 * 
 * ages[y] <= 0.5 * ages[x] + 7
 * ages[y] > ages[x]
 * ages[y] > 100 && ages[x] < 100
 * 
 * 
 * 否则，x 将会向 y 发送一条好友请求。
 * 
 * 注意，如果 x 向 y 发送一条好友请求，y 不必也向 x 发送一条好友请求。另外，用户不会向自己发送好友请求。
 * 
 * 返回在该社交媒体网站上产生的好友请求总数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：ages = [16,16]
 * 输出：2
 * 解释：2 人互发好友请求。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：ages = [16,17,18]
 * 输出：2
 * 解释：产生的好友请求为 17 -> 16 ，18 -> 17 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：ages = [20,30,100,110,120]
 * 输出：3
 * 解释：产生的好友请求为 110 -> 100 ，120 -> 110 ，120 -> 100 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == ages.length
 * 1 <= n <= 2 * 10^4
 * 1 <= ages[i] <= 120
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        //1.先反转
        sort(ages.begin(), ages.end());
        int n = ages.size();
        int left = 0, right = 0;
        int ans = 0;
        //每一轮计算这个age要给多少人发请求
        for (int age : ages) {
            //小于15的数一定不会给左边发消息 14 * 0.5 + 7 = 14
            if (age < 15) continue;;
            //left是区间第一个满足的
            while (ages[left] <= 0.5 * age + 7) {
                left++;
            }
            //right是最后一个满足的
            while (right + 1 < n && ages[right + 1] <= age) {
                right++;
            }
            ans += (right - left);
        }
        return ans;
    }
};
// @lc code=end

