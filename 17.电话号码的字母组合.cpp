/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (60.44%)
 * Likes:    2904
 * Dislikes: 0
 * Total Accepted:    954.9K
 * Total Submissions: 1.6M
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    vector<string> ret; //  用来返回最终数组
    string str = ""; //  用来回溯的

    vector<string> alps {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
    vector<string> letterCombinations(string digits) {
        if(digits == "")
        {
            return ret;
        }
        //  1. 将数字映射成字符数组
        vector<string> vec;
        for(auto c : digits)
        {
            int index = c - '0' - 2;
            vec.push_back(alps[index]);
        }

        int len = digits.size();
 
        //  2.  开始回溯
        func(0, vec, len);

        //  3.  返回
        return ret;
    }

    void func (int i, vector<string> vec, const int len)
    {
        if(i == len)
        {
            ret.push_back(str);
        }
        else
        {
            for(int k = 0; k < vec[i].size(); k++)
            {
                str += vec[i][k];
                func(i + 1,vec,len);
                str.pop_back();
            }
        }
    }
};
// @lc code=end

