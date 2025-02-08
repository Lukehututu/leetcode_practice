/*
 * @lc app=leetcode.cn id=777 lang=cpp
 *
 * [777] 在LR字符串中交换相邻字符
 *
 * https://leetcode.cn/problems/swap-adjacent-in-lr-string/description/
 *
 * algorithms
 * Medium (38.62%)
 * Likes:    297
 * Dislikes: 0
 * Total Accepted:    30.6K
 * Total Submissions: 78.5K
 * Testcase Example:  '"RXXLRXRXL"\n"XRLXXRRLX"'
 *
 * 在一个由 'L' , 'R' 和 'X' 三个字符组成的字符串（例如"RXXLRXRXL"）中进行移动操作。一次移动操作指用一个 "LX" 替换一个
 * "XL"，或者用一个 "XR" 替换一个 "RX"。现给定起始字符串 start 和结束字符串 result，请编写代码，当且仅当存在一系列移动操作使得
 * start 可以转换成 result 时， 返回 True。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：start = "RXXLRXRXL", result = "XRLXXRRLX"
 * 输出：true
 * 解释：通过以下步骤我们可以将 start 转化为 result：
 * RXXLRXRXL ->
 * XRXLRXRXL ->
 * XRLXRXRXL ->
 * XRLXXRRXL ->
 * XRLXXRRLX
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：start = "X", result = "L"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= start.length <= 10^4
 * start.length == result.length
 * start 和 result 都只包含 'L', 'R' 或 'X'。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canTransform(string start, string result) {
        int n =  start.size();
        //1.X本质上是个占位符，R和L是不会换位置的，因此只有去掉X后LR相同才能换
        string s1, s2;
        for(char ch : start) if(ch != 'X') s1.push_back(ch);
        for(char ch : result) if(ch != 'X') s2.push_back(ch);
        if(s1 != s2) return false;
        
        //2.检验LR交换顺序是否正确
        int i = 0, j = 0;
        while(i < n && j < n) {
            while(i < n && start[i] == 'X') ++i;
            while(j < n && result[j] == 'X') ++j;

            if(i >= n || j >= n) return i == j;
            //因为如果是L那只能是向左移因此start对应的index一定更大或者没移动
            if(start[i] == 'L' && i < j) return false;
            if(start[i] == 'R' && i > j) return false;

            i++;
            j++;
        }
        return true;
    }
};
// @lc code=end

