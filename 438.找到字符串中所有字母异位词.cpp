/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (53.44%)
 * Likes:    1525
 * Dislikes: 0
 * Total Accepted:    533.7K
 * Total Submissions: 996.7K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int len_p = p.size();
        int len_s = s.size();
        if(len_p > len_s)
            return vector<int>();

        int i = 0;
        auto it = s.begin();    //  迭代器方便构造tmp
        vector<int> ret;    //  返回数组

        //  构建p的字符桶
        unordered_map<char,int> buc_p;
        for(auto ch : p)
        {
            buc_p[ch]++;
        }

        //  构建一个滑动窗口
        unordered_map<char,int> wnd;
        //  先用前len_p个字符来初始化它
        for(int j = 0; j < len_p ; j++)
        {
            wnd[s[j]]++;
        }

        while(i < len_s - len_p + 1)    //  最后还剩不到len_p个字符时跳出
        {
            if (wnd == buc_p)
            {
                ret.push_back(i);
            }
            //  将第i个字符抹去
            wnd[s[i]]--;
            if (wnd[s[i]] == 0)//    说明已经没有这个字符了，那就删除
            {
                wnd.erase(s[i]);
            }

            //  将第i + len 1个字符包含进来
            wnd[s[i + len_p]]++;
            //  i迭代
            i++;
        }
        return ret;
    }
};
// @lc code=end

