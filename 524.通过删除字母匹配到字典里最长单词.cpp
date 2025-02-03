/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 *
 * https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (50.32%)
 * Likes:    380
 * Dislikes: 0
 * Total Accepted:    113.8K
 * Total Submissions: 225.2K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * 给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s
 * 中的某些字符得到。
 * 
 * 如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
 * 输出："apple"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abpcplea", dictionary = ["a","b","c"]
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 1000
 * s 和 dictionary[i] 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:


    bool isSubSeq(const string& s, const string& word) {
        if(s.size() < word.size()) return false;
        int i = 0;
        for(char ch : word) {
            while(i < s.size() && s[i] != ch) i++;
            if(i == s.size()) return false;
            i++;
        }
        return true;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b) {
            if(a.length() != b.length()) {
                return a.length() > b.length(); 
            }
            else {
                return a < b;
            }
        });
        
        for(auto word : dictionary) {
            if(isSubSeq(s, word)) return word;
        }
        return "";
    }
};
// @lc code=end

