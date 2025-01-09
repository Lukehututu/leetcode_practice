/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (52.70%)
 * Likes:    939
 * Dislikes: 0
 * Total Accepted:    101.4K
 * Total Submissions: 192K
 * Testcase Example:  '"aaabb"\n3'
 *
 * 给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
 * 
 * 如果不存在这样的子字符串，则返回 0。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aaabb", k = 3
 * 输出：3
 * 解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "ababbc", k = 2
 * 输出：5
 * 解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由小写英文字母组成
 * 1 <= k <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        int n = s.length();
        for(int req = 1; req <= min(26, n); ++req) {
            vector<int> collect(26,0);
            int satisfied = 0;
            int cnt = 0;
            for(int i = 0, j = 0; j < n; ++j) {
                int idx = s[j] - 'a';
                collect[idx]++;
                if(collect[idx] == 1) {
                    cnt++;
                }
                if(collect[idx] == k) {
                    satisfied++;
                }

                //如果此时包含的字符数超过了本轮规定的字符数那就i右移
                while(cnt > req) {
                    idx = s[i++] - 'a';
                    collect[idx]--;
                    if(collect[idx] == 0) {
                        cnt--;
                    }
                    if(collect[idx] == k - 1) {
                        satisfied--;
                    }
                }
                
                if(satisfied == req) ans = max(ans, j - i + 1);
            } 
        }
        return ans;
    }
};
// @lc code=end

